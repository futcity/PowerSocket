/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "boards.h"

#ifdef BOARD_NODEMCU_R4

#define RELAY_PIN_0     D1
#define RELAY_PIN_1     D2
#define RELAY_PIN_2     D3
#define RELAY_PIN_3     D4

uint8_t Buttons[] = {
};

uint8_t ButtonsCount = ARRAY_ITEMS_COUNT(Buttons);

uint8_t Relays[] = {
    RELAY_PIN_0,
    RELAY_PIN_1,
    RELAY_PIN_2,
    RELAY_PIN_3
};

uint8_t RelaysCount = ARRAY_ITEMS_COUNT(Relays);

uint8_t Leds[] = {
};

uint8_t LedsCount = ARRAY_ITEMS_COUNT(Leds);

void BoardInit()
{
    for (uint8_t i = 0; i < ButtonsCount; i++) {
        pinMode(Buttons[i], INPUT_PULLUP);
    }

    for (uint8_t i = 0; i < RelaysCount; i++) {
        pinMode(Relays[i], OUTPUT);
    }

    for (uint8_t i = 0; i < LedsCount; i++) {
        pinMode(Leds[i], OUTPUT);
    }
}

void BoardRelaySwitch(uint8_t id, bool state)
{
    if (state) {
        digitalWrite(Relays[id], LOW);
    } else {
        digitalWrite(Relays[id], HIGH);
    }
}

void BoardLedSwitch(uint8_t id, bool state)
{
    if (state) {
        digitalWrite(Leds[id], HIGH);
    } else {
        digitalWrite(Leds[id], LOW);
    }
}

#endif