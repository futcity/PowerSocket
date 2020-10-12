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

WidgetLED *LedWidgets[] = {
    &LedStatus0,
    &LedStatus1,
    &LedStatus2,
    &LedStatus3
};

void PortsInit()
{
    LedStatus0.setVPin(VP_LED_STATUS_0);
    LedStatus1.setVPin(VP_LED_STATUS_1);
    LedStatus2.setVPin(VP_LED_STATUS_2);
    LedStatus3.setVPin(VP_LED_STATUS_3);
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
    }
}

BLYNK_CONNECTED()
{
    Blynk.syncAll();
}

BLYNK_WRITE(VP_STATUS_ON_0)
{
    const uint8_t id = 0;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_ON_1)
{
    const uint8_t id = 1;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_ON_2)
{
    const uint8_t id = 2;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_ON_3)
{
    const uint8_t id = 3;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_OFF_0)
{
    const uint8_t id = 0;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_OFF_1)
{
    const uint8_t id = 1;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_OFF_2)
{
    const uint8_t id = 2;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_OFF_3)
{
    const uint8_t id = 3;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_SWITCH_0)
{
    const uint8_t id = 0;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    } else {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_SWITCH_1)
{
    const uint8_t id = 1;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    } else {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_SWITCH_2)
{
    const uint8_t id = 2;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    } else {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}

BLYNK_WRITE(VP_STATUS_SWITCH_3)
{
    const uint8_t id = 3;

    if (param.asInt() == TRUE) {
        RelaySetStatus(id, true);
    } else {
        RelaySetStatus(id, false);
    }

    RelayUpdate(id);
}
