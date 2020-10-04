/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "relay.h"
#include "boards.h"
#include "ports.h"
#include "common.h"

void RelaySwitch(uint8_t id, bool state)
{
    if (state) {
#ifndef INVERT_MODE
        digitalWrite(Relays[id], HIGH);
#else
        digitalWrite(Relays[id], LOW);
#endif
        digitalWrite(Leds[id], HIGH);
        VirtualWriteSwitch(id, TRUE);
        LedWidgets[id]->on();
    } else {
#ifndef INVERT_MODE
        digitalWrite(Relays[id], LOW);
#else
        digitalWrite(Relays[id], HIGH);
#endif
        digitalWrite(Leds[id], LOW);
        VirtualWriteSwitch(id, FALSE);
        LedWidgets[id]->off();
    }
}