/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/*
 * DEVICE HARDWARE
 */
#define DEVICE_NODEMCU_V1
//#define DEVICE_SONOFF_V2
//#define DEVICE_SONOFF_V3

//#define NAROD_MON_ENABLED

/*
 * APPLICATION DEFINES
 */
#define DEVICE_KEY  ""

#define WIFI_SSID   ""
#define WIFI_PASSWD ""

#define SERVER_ADDR ""
#define SERVER_PORT 8080

#define MAIN_TMR_DELAY      1000

#define LED_ON          255
#define LED_OFF         0
#define TRUE            1
#define FALSE           0
#define SERIAL_SPEED    9600

/*
 * VIRTUAL PINS DEFINES
 */
#define VP_STATUS_SWITCH    V0
#define VP_STATUS_ON        V1
#define VP_STATUS_OFF       V2
#define VP_LED_STATUS       V3

/*
 * GPIO DEFINES
 */
#ifdef DEVICE_NODEMCU_V1
#define RELAY_PIN   D1
#define BUTTON_PIN  D5
#endif

void MainTimerCallback();

/*
 * APPLICATION CLASSES
 */
SimpleTimer MainTimer;
WidgetLED LedStatus(VP_LED_STATUS);

/*
 * APPLICATION VARIABLES
 */
 bool Status = false;

/*
 * BLYNK CALLBACKS
 */
BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(VP_STATUS_ON)
{
    if (param.asInt() == TRUE) {
        Status = true;
        Blynk.virtualWrite(VP_STATUS_SWITCH, TRUE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_OFF)
{
    if (param.asInt() == TRUE) {
        Status = false;
        Blynk.virtualWrite(VP_STATUS_SWITCH, FALSE);
    }
    MainTimerCallback();
}

BLYNK_WRITE(VP_STATUS_SWITCH)
{
    if (param.asInt() == TRUE) {
        Status = true;
    } else {
        Status = false;
    }
    MainTimerCallback();
}

/*
 * OTHER FUNCTIONS
 */
void MainTimerCallback()
{
    if (Status) {
        pinMode(RELAY_PIN, OUTPUT);
        digitalWrite(RELAY_PIN, HIGH);
        LedStatus.on();
    } else {
        pinMode(RELAY_PIN, INPUT);
        digitalWrite(RELAY_PIN, LOW);
        LedStatus.off();
    }
}

void ReadButton()
{
    if (digitalRead(BUTTON_PIN) == LOW) {
        Status = !Status;
        if (Status) {
            Blynk.virtualWrite(VP_STATUS_SWITCH, TRUE);
            LedStatus.on();
        } else {
            Blynk.virtualWrite(VP_STATUS_SWITCH, FALSE);
            LedStatus.off();
        }
        MainTimerCallback();
        delay(600);
    }
}

/*
 * APPLICATION MAIN FUNCTIONS
 */
void setup()
{
    Serial.begin(SERIAL_SPEED);
    Blynk.begin(DEVICE_KEY, WIFI_SSID, WIFI_PASSWD, SERVER_ADDR, SERVER_PORT);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(RELAY_PIN, INPUT);

    MainTimer.setInterval(MAIN_TMR_DELAY, MainTimerCallback);
}

void loop()
{
    Blynk.run();
    MainTimer.run();
    ReadButton();
}
