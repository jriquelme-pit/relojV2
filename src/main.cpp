#include <Arduino.h>

#include "Adafruit_ST7735.h"

#include "ArduinoJson.h"

#include "utils.h"
#include "model/Hora.h"
#include "model/Fecha.h"
#include "model/Clima.h"
#include "lcd.h"
#include "red.h"


#define ligth 4 //D2

Hora hora = Hora();
Fecha fecha = Fecha();
Clima clima = Clima();
Lcd lcd = Lcd();
Red red = Red();


void setup() {

    Serial.begin(19200);
    pinMode(ligth, OUTPUT);

    analogWrite(ligth, 255);
    lcd.cargandoDatos();
    //String ip = red.connect();
    //Serial.println("Obteniendo el tiempo");
    //String datosTiempo = red.getDate();
    //Serial.println(datosTiempo);
    //hora.setData(datosTiempo);

    clima.dummy();


    lcd.clear();
    lcd.printPlantilla();
    lcd.printFecha(fecha);
    lcd.printHora(hora);
    lcd.printClima(clima);








}
void loop() {
    delay(1000);
    lcd.printHora(hora);

    /*analogWrite(ligth, 1);
    delay(500);
    analogWrite(ligth, 50);
    delay(500);
    analogWrite(ligth, 100);
    delay(500);
    analogWrite(ligth, 150);
    delay(500);
    analogWrite(ligth, 200);
    delay(500);
    analogWrite(ligth, 255);
    delay(500);
*/
}