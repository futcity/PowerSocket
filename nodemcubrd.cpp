/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include "boards.h"

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

#define LED_PIN_0		D0

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

uint8_t Leds[] = {
	LED_PIN_0
};

#endif