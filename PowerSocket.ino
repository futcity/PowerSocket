/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "common.h"
#include "timers.h"

/*
 * DEVICE HARDWARE
 */
#define BOARD_NODEMCU_V1
//#define BOARD_SONOFF_V2
//#define BOARD_SONOFF_V3

//#define MULTIPLE_RELAY

#define INVERT_MODE

/*
 * APPLICATION DEFINES
 */
#define DEVICE_KEY  ""

#define WIFI_SSID   ""
#define WIFI_PASSWD ""

#define SERVER_ADDR ""
#define SERVER_PORT 8080

#define RELAYS_COUNT    1
#define BUTTONS_COUNT   1

#define MAIN_TMR_DELAY  1000
#define LED_ON          255
#define LED_OFF         0
#define TRUE            1
#define FALSE           0
#define SERIAL_SPEED    9600

/*
 * VIRTUAL PINS DEFINES
 */
#define VP_STATUS_SWITCH_0  V0
#define VP_STATUS_SWITCH_1  V1
#define VP_STATUS_SWITCH_2  V2
#define VP_STATUS_SWITCH_3  V3
#define VP_STATUS_SWITCH_4  V4
#define VP_STATUS_SWITCH_5  V5
#define VP_STATUS_SWITCH_6  V6
#define VP_STATUS_SWITCH_7  V7

#define VP_STATUS_ON_0      V10
#define VP_STATUS_ON_1      V11
#define VP_STATUS_ON_2      V12
#define VP_STATUS_ON_3      V13
#define VP_STATUS_ON_4      V14
#define VP_STATUS_ON_5      V15
#define VP_STATUS_ON_6      V16
#define VP_STATUS_ON_7      V17

#define VP_STATUS_OFF_0     V20
#define VP_STATUS_OFF_1     V21
#define VP_STATUS_OFF_2     V22
#define VP_STATUS_OFF_3     V23
#define VP_STATUS_OFF_4     V24
#define VP_STATUS_OFF_5     V25
#define VP_STATUS_OFF_6     V26
#define VP_STATUS_OFF_7     V27

#define VP_LED_STATUS_0     V30
#define VP_LED_STATUS_1     V31
#define VP_LED_STATUS_2     V32
#define VP_LED_STATUS_3     V33
#define VP_LED_STATUS_4     V34
#define VP_LED_STATUS_5     V35
#define VP_LED_STATUS_6     V36
#define VP_LED_STATUS_7     V37

/*
 * GPIO DEFINES
 */
#ifdef BOARD_NODEMCU_V1
#define RELAY_PIN_0     D1
#define RELAY_PIN_1     D2
#define RELAY_PIN_2     D3
#define RELAY_PIN_3     D4
#define RELAY_PIN_4     D5
#define RELAY_PIN_5     D6
#define RELAY_PIN_6     D7
#define RELAY_PIN_7     D8

#define BUTTON_PIN_0    D5
#define BUTTON_PIN_1    D6
#endif

void MainTimerCallback();

/*
 * APPLICATION CLASSES
 */
SimpleTimer MainTimer;
WidgetLED LedStatus0(VP_LED_STATUS_0);
WidgetLED LedStatus1(VP_LED_STATUS_1);
WidgetLED LedStatus2(VP_LED_STATUS_2);
WidgetLED LedStatus3(VP_LED_STATUS_3);
WidgetLED LedStatus4(VP_LED_STATUS_4);
WidgetLED LedStatus5(VP_LED_STATUS_5);
WidgetLED LedStatus6(VP_LED_STATUS_6);
WidgetLED LedStatus7(VP_LED_STATUS_7);

/*
 * APPLICATION VARIABLES
 */


#ifdef BOARD_NODEMCU_V1
uint8_t Buttons[] = {
    BUTTON_PIN_0,
    BUTTON_PIN_1
};

uint8_t Relays[] = {
    RELAY_PIN_0,
    RELAY_PIN_1,
    RELAY_PIN_2,
    RELAY_PIN_3,
    RELAY_PIN_4,
    RELAY_PIN_5,
    RELAY_PIN_6,
    RELAY_PIN_7
};
#endif

WidgetLED *Leds[] = {
    &LedStatus0,
    &LedStatus1,
    &LedStatus2,
    &LedStatus3,
    &LedStatus4,
    &LedStatus5,
    &LedStatus6,
    &LedStatus7
};

/*
 * BLYNK CALLBACKS
 */
BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(VP_STATUS_ON_0)
{
    if (param.asInt() == TRUE) {
        Statuses[0] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_0, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_1)
{
    if (param.asInt() == TRUE) {
        Statuses[1] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_1, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_2)
{
    if (param.asInt() == TRUE) {
        Statuses[2] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_2, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_3)
{
    if (param.asInt() == TRUE) {
        Statuses[3] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_3, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_4)
{
    if (param.asInt() == TRUE) {
        Statuses[4] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_4, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_5)
{
    if (param.asInt() == TRUE) {
        Statuses[5] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_5, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_6)
{
    if (param.asInt() == TRUE) {
        Statuses[6] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_6, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_ON_7)
{
    if (param.asInt() == TRUE) {
        Statuses[7] = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH_7, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_0)
{
    if (param.asInt() == TRUE) {
        Statuses[0] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_0, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_1)
{
    if (param.asInt() == TRUE) {
        Statuses[1] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_1, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_2)
{
    if (param.asInt() == TRUE) {
        Statuses[2] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_2, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_3)
{
    if (param.asInt() == TRUE) {
        Statuses[3] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_3, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_4)
{
    if (param.asInt() == TRUE) {
        Statuses[4] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_4, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_5)
{
    if (param.asInt() == TRUE) {
        Statuses[5] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_5, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_6)
{
    if (param.asInt() == TRUE) {
        Statuses[6] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_6, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF_7)
{
    if (param.asInt() == TRUE) {
        Statuses[7] = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH_7, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_0)
{
    if (param.asInt() == TRUE) {
        Statuses[0] = true;
    } else {
        Statuses[0] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_1)
{
    if (param.asInt() == TRUE) {
        Statuses[1] = true;
    } else {
        Statuses[1] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_2)
{
    if (param.asInt() == TRUE) {
        Statuses[2] = true;
    } else {
        Statuses[2] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_3)
{
    if (param.asInt() == TRUE) {
        Statuses[3] = true;
    } else {
        Statuses[3] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_4)
{
    if (param.asInt() == TRUE) {
        Statuses[4] = true;
    } else {
        Statuses[4] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_5)
{
    if (param.asInt() == TRUE) {
        Statuses[5] = true;
    } else {
        Statuses[5] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_6)
{
    if (param.asInt() == TRUE) {
        Statuses[6] = true;
    } else {
        Statuses[6] = false;
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH_7)
{
    if (param.asInt() == TRUE) {
        Statuses[7] = true;
    } else {
        Statuses[7] = false;
    }
    MainTimerCallback();
}

/*
 * OTHER FUNCTIONS
 */
void VirtualWriteSwitch(uint8_t id, uint8_t value)
{
    switch (id) {
        case 0: Blynk.virtualWrite(VP_STATUS_SWITCH_0, value);
            break;
        case 1: Blynk.virtualWrite(VP_STATUS_SWITCH_1, value);
            break;
        case 2: Blynk.virtualWrite(VP_STATUS_SWITCH_2, value);
            break;
        case 3: Blynk.virtualWrite(VP_STATUS_SWITCH_3, value);
            break;
        case 4: Blynk.virtualWrite(VP_STATUS_SWITCH_4, value);
            break;
        case 5: Blynk.virtualWrite(VP_STATUS_SWITCH_5, value);
            break;
        case 6: Blynk.virtualWrite(VP_STATUS_SWITCH_6, value);
            break;
        case 7: Blynk.virtualWrite(VP_STATUS_SWITCH_7, value);
            break;
    }
}

void MainTimerCallback()
{
    for (uint8_t i = 0; i < RELAYS_COUNT; i++) {
        if (!Statuses[i]) {
#ifdef MULTIPLE_RELAY
            digitalWrite(Relays[i], LOW);
#else
#ifdef INVERT_MODE
            pinMode(Relays[i], OUTPUT);
#else
            pinMode(Relays[i], INPUT);
#endif
#endif
            Leds[i]->off();
        } else {
            Leds[i]->on();
#ifdef MULTIPLE_RELAY
            digitalWrite(Relays[i], HIGH);
#else
#ifdef INVERT_MODE
            pinMode(Relays[i], INPUT);
#else
            pinMode(Relays[i], OUTPUT);
#endif
#endif
        }
    }
}

void ReadButton()
{
    for (uint8_t i = 0; i < BUTTONS_COUNT; i++) {
        if (digitalRead(Buttons[i]) == LOW) {
            Statuses[i] = !Statuses[i];
            if (Statuses[i]) {
                VirtualWriteSwitch(i, TRUE);
            } else {
                VirtualWriteSwitch(i, FALSE);
            }
            MainTimerCallback();
            delay(600);
        }
    }
}

/*
 * APPLICATION MAIN FUNCTIONS
 */
void setup()
{
    Serial.begin(SERIAL_SPEED);
    Blynk.begin(DEVICE_KEY, WIFI_SSID, WIFI_PASSWD, SERVER_ADDR, SERVER_PORT);

    for (uint8_t i = 0; i < BUTTONS_COUNT; i++) {
        pinMode(Buttons[i], INPUT_PULLUP);
    }

    for (uint8_t i = 0; i < BUTTONS_COUNT; i++) {
#ifdef MULTIPLE_RELAY
        pinMode(Relays[i], OUTPUT);
#else
        pinMode(Relays[i], INPUT);
#endif
    }

    MainTimer.setInterval(MAIN_TMR_DELAY, MainTimerCallback);
}

void loop()
{
    Blynk.run();
    MainTimer.run();
    ReadButton();
}
