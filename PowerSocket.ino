/*
 * Future City Project
 *
 * Copyright (C) 2020 Sergey Denisov. GPLv3
 *
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 */

#include <ESP8266WiFi.h>

#include "ports.h"
#include "boards.h"
#include "common.h"
#include "relay.h"

static void ReadButton()
{
    for (uint8_t i = 0; i < ButtonsCount; i++) {
        if (digitalRead(Buttons[i]) == LOW) {
            RelaySwitchStatus(i);
            RelayUpdate(i);
            delay(600);
        }
    }
}

void setup()
{
    BoardInit();
    PortsInit();
    Blynk.begin(DEVICE_KEY, WIFI_SSID, WIFI_PASSWD, BLYNK_SERVER, BLYNK_SERVER_PORT);
}

void loop()
{
    Blynk.run();
    ReadButton();
}
