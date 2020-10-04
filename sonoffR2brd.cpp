/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "boards.h"

#ifdef BOARD_SONOFF_R2

#define RELAY_PIN_0     12
#define BUTTON_PIN_0    0
#define LED_PIN_0       13

uint8_t Buttons[] = {
    BUTTON_PIN_0
};

uint8_t Relays[] = {
    RELAY_PIN_0
};

uint8_t Leds[] = {
    LED_PIN_0
};

#endif