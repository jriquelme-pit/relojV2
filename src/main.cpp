#include <Arduino.h>
#include "SPI.h"

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#include "Time.h"
#include "TimeLib.h"

#include "ArduinoJson.h"

#include "ESP8266WiFi.h"
#include "WiFiClientSecure.h"
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;     // your network SSID (name)
char password[] = SECRET_PASS;  // your network key

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
//Add a SSL client
WiFiClientSecure client;

String clima = "{\"a\":{\"1\":00,\"2\":00},\"b\":{\"1\":00,\"2\":00}}";


void setup() {

    tft.begin();
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
}