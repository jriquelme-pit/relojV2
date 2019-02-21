#include <Arduino.h>

#include "Adafruit_ST7735.h"

#include "ArduinoJson.h"

#include "utils.h"
#include "model/Hora.h"
#include "model/Fecha.h"
#include "model/Clima.h"
#include "lcd.h"
#include "red.h"


Hora hora = Hora();
Fecha fecha = Fecha();
Clima clima = Clima();
Lcd lcd = Lcd();
Red red = Red();

void setup() {

    Serial.begin(19200);


    lcd.cargandoDatos();
    String ip = red.connect();
    /*lcd.conectado(ip);
    String clima = red.getWeather();

    DynamicJsonBuffer jsonBuffer;
    JsonObject &root = jsonBuffer.parseObject(clima);
    Serial.println("obteniendo info");
    Serial.println(root["a"]["1"].as<String>());
    Serial.println("obteniendo final");
*/
    lcd.clear();
    lcd.printFecha(fecha);
    lcd.printHora(hora);

}

void loop() {


}