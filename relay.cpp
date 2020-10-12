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

bool Statuses[MAX_STATUSES];

/*
 * Public functions
 */

bool RelayGetStatus(uint8_t id)
{
    return Statuses[id];
}

void RelaySetStatus(uint8_t id, bool val)
{
    Statuses[id] = val;
}

void RelaySwitchStatus(uint8_t id)
{
    Statuses[id] = !Statuses[id];
}

void RelayUpdate(uint8_t id)
{
    if (RelayGetStatus(id)) {
        BoardRelaySwitch(id, true);
        BoardLedSwitch(id, true);
        VirtualWriteSwitch(id, TRUE);
        LedWidgets[id]->on();
    } else {
        BoardRelaySwitch(id, false);
        BoardLedSwitch(id, false);
        VirtualWriteSwitch(id, FALSE);
        LedWidgets[id]->off();
    }
}
