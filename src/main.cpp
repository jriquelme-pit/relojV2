#include <Arduino.h>

#include "Adafruit_ST7735.h"

#include "ArduinoJson.h"

#include <Wire.h>
#include "RTClib.h"

#include "utils.h"
#include "model/Hora.h"
#include "model/Fecha.h"
#include "model/Clima.h"
#include "lcd.h"
#include "red.h"


#define ligth 15 //D2

Hora hora = Hora();
Fecha fecha = Fecha();
Clima clima = Clima();
Lcd lcd = Lcd();
Red red = Red();

RTC_DS3231 rtc;

void updateDataWeater() {
    bool exito = false;
    do {
        String datosTiempo = red.getWeather(true);
        exito = clima.parserJson(datosTiempo);
    } while (!exito);
}

static unsigned long timeMillis;
static unsigned long timeMillisHours = 0;
int hours = -1;


void setup() {

    if (!rtc.begin()) {
        Serial.println(F("Couldn't find RTC"));
        while (1);
    }
    if (rtc.lostPower()) {
        // Fijar a fecha y hora de compilacion
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

        // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
        // rtc.adjust(DateTime(2016, 1, 21, 3, 0, 0));
    }
    fecha.refresh(rtc.now());
    hora.refresh(rtc.now());
    Serial.begin(19200);
    pinMode(ligth, OUTPUT);

    updateDataWeater();

    analogWrite(ligth, 255);
    lcd.cargandoDatos();


    lcd.clear();
    lcd.printPlantilla();
    lcd.printFecha(fecha);
    lcd.printHora(hora);
    lcd.printClima(clima);
    lcd.printClimaActual(clima, hora);
    timeMillis = millis();

}

void setBrightness() {

    if (hora.hora >= 8 and hora.hora < 19) {
        analogWrite(ligth, 255);
    } else if (hora.hora = 19) {
        analogWrite(ligth, 200);
    } else if (hora.hora = 20) {
        analogWrite(ligth, 150);
    } else if (hora.hora = 22) {
        analogWrite(ligth, 100);
    } else if (hora.hora >= 23 and hora.hora < 7) {
        analogWrite(ligth, 1);
    } else if (hora.hora = 7) {
        analogWrite(ligth, 150);
    }

}


void loop() {
    if (millis() - timeMillis > 1000) {
        timeMillis = millis();
        fecha.refresh(rtc.now());
        hora.refresh(rtc.now());

        if ((hora.hora == 2 || hora.hora == 6 || hora.hora == 14) && hora.minuto == 0) {
            updateDataWeater();
            lcd.printClima(clima);
        }
        lcd.printHora(hora);
        lcd.printFecha(fecha);
        setBrightness();

        if (hora.hora != hours and hora.minuto == 0) {
            Serial.println(hora.toString());
            lcd.printClimaActual(clima, hora);
            hours = hora.hora;
        }
    }

}