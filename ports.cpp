/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "ports.h"
#include "common.h"
#include "relay.h"

WidgetLED LedStatus0(Blynk);
WidgetLED LedStatus1(Blynk);
WidgetLED LedStatus2(Blynk);
WidgetLED LedStatus3(Blynk);
WidgetLED LedStatus4(Blynk);
WidgetLED LedStatus5(Blynk);
WidgetLED LedStatus6(Blynk);
WidgetLED LedStatus7(Blynk);

WidgetLED *LedWidgets[] = {
    &LedStatus0,
    &LedStatus1,
    &LedStatus2,
    &LedStatus3,
    &LedStatus4,
    &LedStatus5,
    &LedStatus6,
    &LedStatus7
};

void PortsInit()
{
    LedStatus0.setVPin(VP_LED_STATUS_0);
    LedStatus1.setVPin(VP_LED_STATUS_1);
    LedStatus2.setVPin(VP_LED_STATUS_2);
    LedStatus3.setVPin(VP_LED_STATUS_3);
    LedStatus4.setVPin(VP_LED_STATUS_4);
    LedStatus5.setVPin(VP_LED_STATUS_5);
    LedStatus6.setVPin(VP_LED_STATUS_6);
    LedStatus7.setVPin(VP_LED_STATUS_7);
}

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

BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(VP_STATUS_ON_0)
{
    const uint8_t pin = 0;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_1)
{
    const uint8_t pin = 1;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_2)
{
    const uint8_t pin = 2;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_3)
{
    const uint8_t pin = 3;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_4)
{
    const uint8_t pin = 4;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_5)
{
    const uint8_t pin = 5;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_6)
{
    const uint8_t pin = 6;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_ON_7)
{
    const uint8_t pin = 7;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_0)
{
    const uint8_t pin = 0;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_1)
{
    const uint8_t pin = 1;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_2)
{
    const uint8_t pin = 2;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_3)
{
    const uint8_t pin = 3;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_4)
{
    const uint8_t pin = 4;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_5)
{
    const uint8_t pin = 5;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_6)
{
    const uint8_t pin = 6;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_OFF_7)
{
    const uint8_t pin = 7;

    if (param.asInt() == TRUE) {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_0)
{
    const uint8_t pin = 0;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_1)
{
    const uint8_t pin = 1;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_2)
{
    const uint8_t pin = 2;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_3)
{
    const uint8_t pin = 3;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_4)
{
    const uint8_t pin = 4;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_5)
{
    const uint8_t pin = 5;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_6)
{
    const uint8_t pin = 6;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}

BLYNK_WRITE(VP_STATUS_SWITCH_7)
{
    const uint8_t pin = 7;

    if (param.asInt() == TRUE) {
        Statuses[pin] = true;
    } else {
        Statuses[pin] = false;
    }

    RelaySwitch(pin, Statuses[pin]);
}