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

//#define BOARD_NODEMCU_V1
#define BOARD_SONOFF_R2
//#define BOARD_SONOFF_R3

//#define INVERT_MODE

#define RELAYS_COUNT    1
#define BUTTONS_COUNT   1
#define LEDS_COUNT      1

extern uint8_t Buttons[];
extern uint8_t Relays[];
extern uint8_t Leds[];

#endif