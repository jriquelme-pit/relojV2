#include <Arduino.h>
#include "SPI.h"

#include "Adafruit_GFX.h"
#include "Adafruit_ST7735.h"

#include "Time.h"
#include "TimeLib.h"

#include "ArduinoJson.h"



#include "lcd.h"
#include "red.h"


Lcd lcd = Lcd();
Red red = Red();

void setup() {

  Serial.begin(19200);


  lcd.cargandoDatos();
  String ip = red.connect();
  lcd.conectado(ip);
  String clima = red.getWeather();

    DynamicJsonBuffer jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(clima);
    Serial.println("obteniendo info");
    Serial.println(root["a"]["1"].as<String>());
    Serial.println("obteniendo final");
}

void loop() {



}