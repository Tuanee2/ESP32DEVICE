#ifndef CONFIG_H
#define CONFIG_H

// LIBRARIES
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <PubSubClient.h>
#include <RTClib.h>

// Biến nút ấn

#define but1 13
#define but2 12
#define but3 14

// text

const char* appText[] = {
  "WIFI",
  "CLOCK",
  "WEATHER",
  "IOT",
  "SETUP",
  "BACK",
};

const char* wifiText[] = {
  "CONNECT WIFI",
  "OLD WIFI",
  "BACK"
};

const char* setupText[] = {
  "SET COLOR",
  "% BAT",
  "SOON",
  "SOON",
  "BACK"
};

const char* clokText[] = {
  "ALARM",
  "STOP WATCH",
  "TIMER",
  "SET TIME",
  "BACK"
};

const char* weatherText[] = {
};

const char* IOTText[] = {
  "SET LED",
  "BACK"
};

// LOCATION

#define defaultLocation "HaNoi"

// TIME

#define secondDefault 0
#define minusDefault 0
#define hourDefault 0
#define dayDefault 0
#define weekDefault 0
#define monthDefault 0
#define yearDefault 0

// mouse

#define default_mouse_position 0

// WEATHER


#endif