/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#ifndef __RELAY_H__
#define __RELAY_H__

#include <Arduino.h>

#define MAX_STATUSES  8

bool RelayGetStatus(uint8_t id);
void RelaySetStatus(uint8_t id, bool val);
void RelaySwitchStatus(uint8_t id);
void RelayUpdate(uint8_t id);

#endif
