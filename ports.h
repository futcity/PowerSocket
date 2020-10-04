/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#ifndef __PORTS_H__
#define __PORTS_H__

#include <WidgetLED.h>

#define VP_STATUS_SWITCH_0  V0
#define VP_STATUS_SWITCH_1  V1
#define VP_STATUS_SWITCH_2  V2
#define VP_STATUS_SWITCH_3  V3
#define VP_STATUS_SWITCH_4  V4
#define VP_STATUS_SWITCH_5  V5
#define VP_STATUS_SWITCH_6  V6
#define VP_STATUS_SWITCH_7  V7

#define VP_STATUS_ON_0      V10
#define VP_STATUS_ON_1      V11
#define VP_STATUS_ON_2      V12
#define VP_STATUS_ON_3      V13
#define VP_STATUS_ON_4      V14
#define VP_STATUS_ON_5      V15
#define VP_STATUS_ON_6      V16
#define VP_STATUS_ON_7      V17

#define VP_STATUS_OFF_0     V20
#define VP_STATUS_OFF_1     V21
#define VP_STATUS_OFF_2     V22
#define VP_STATUS_OFF_3     V23
#define VP_STATUS_OFF_4     V24
#define VP_STATUS_OFF_5     V25
#define VP_STATUS_OFF_6     V26
#define VP_STATUS_OFF_7     V27

#define VP_LED_STATUS_0     V30
#define VP_LED_STATUS_1     V31
#define VP_LED_STATUS_2     V32
#define VP_LED_STATUS_3     V33
#define VP_LED_STATUS_4     V34
#define VP_LED_STATUS_5     V35
#define VP_LED_STATUS_6     V36
#define VP_LED_STATUS_7     V37

extern WidgetLED *LedWidgets[];

void PortsInit();
void VirtualWriteSwitch(uint8_t id, uint8_t value);

#endif
