/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#ifndef __BOARDS_H__
#define __BOARDS_H__

#include <Arduino.h>

#define ARRAY_ITEMS_COUNT(_array) \
        (sizeof (_array) / sizeof (*(_array)))

//#define BOARD_SONOFF_R2
#define BOARD_NODEMCU_R4

typedef enum {
    STATUS_LED
} LedType;

typedef enum {
    MAIN_BUTTON
} ButtonType;

typedef enum {
    MAIN_RELAY
} RelayType;

extern uint8_t ButtonsCount;
extern uint8_t RelaysCount;
extern uint8_t LedsCount;

extern uint8_t Buttons[];
extern uint8_t Relays[];
extern uint8_t Leds[];

void BoardInit();
void BoardRelaySwitch(uint8_t id, bool state);
void BoardLedSwitch(uint8_t id, bool state);

#endif