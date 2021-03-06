/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "boards.h"

#ifdef BOARD_SONOFF_R2

#define RELAY_PIN   12

#define BUTTON_PIN  0

#define LED_PIN     12

uint8_t Buttons[] = {
    BUTTON_PIN
};

uint8_t ButtonsCount = ARRAY_ITEMS_COUNT(Buttons);

uint8_t Relays[] = {
    RELAY_PIN
};

uint8_t RelaysCount = ARRAY_ITEMS_COUNT(Relays);

uint8_t Leds[] = {
    LED_PIN
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
        digitalWrite(Relays[id], HIGH);
    } else {
        digitalWrite(Relays[id], LOW);
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