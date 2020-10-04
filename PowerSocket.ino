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
    for (uint8_t i = 0; i < BUTTONS_COUNT; i++) {
        if (digitalRead(Buttons[i]) == LOW) {
            Statuses[i] = !Statuses[i];
            RelaySwitch(i, Statuses[i]);
            delay(600);
        }
    }
}

void setup()
{
    PortsInit();
    Blynk.begin(DEVICE_KEY, WIFI_SSID, WIFI_PASSWD, BLYNK_SERVER, BLYNK_SERVER_PORT);

    for (uint8_t i = 0; i < BUTTONS_COUNT; i++) {
        pinMode(Buttons[i], INPUT_PULLUP);
    }

    for (uint8_t i = 0; i < LEDS_COUNT; i++) {
        pinMode(Leds[i], OUTPUT);
    }

    for (uint8_t i = 0; i < RELAYS_COUNT; i++) {
        pinMode(Relays[i], OUTPUT);
    }
}

void loop()
{
    Blynk.run();
    ReadButton();
}
