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

bool updateDataWeater() {
    String datosTiempo = red.getWeather(true);
    return clima.parserJson(datosTiempo);

}

bool updateFullDate() {

    String datosTiempo = red.getFullDate();
    return clima.parseFullDate(datosTiempo, hora, fecha, rtc);

}

static unsigned long timeMillis;
static unsigned long timeMillisHours = 0;
int hours = -1;


void setBrightness() {

    int l = 1;
    if (hora.hora >= 8 and hora.hora < 19) {
        l = 255;
    } else if (hora.hora == 19) {
        l = 200;
    } else if (hora.hora == 20) {
        l = 150;
    } else if (hora.hora == 21) {
        l = 50;
    } else if (hora.hora >= 22 || hora.hora < 7) {
        l = 2;
    } else if (hora.hora == 7) {
        l = 50;
    }

    Serial.println("brillo: " + String(l));
    analogWrite(ligth, l);

}

void loadAll() {
    lcd.clear();
    lcd.printPlantilla();
    lcd.printFecha(fecha);
    lcd.printHora(hora);
    lcd.printClima(clima);
    lcd.printClimaActual(clima, hora);
}

bool isUpdateDataWeater = false;
bool isUpdateDataFullDate = false;


void setup() {

    if (!rtc.begin()) {
        Serial.println(F("Couldn't find RTC"));
        while (1);
    }
    if (rtc.lostPower()) {
    // Fijar a fecha y hora de compilacion
      rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    // Fijar a fecha y hora específica. En el ejemplo, 21 de Enero de 2016 a las 03:00:00
    //rtc.adjust(DateTime(2016, 1, 21, 15, 59, 55));
    }
    fecha.refresh(rtc.now());
    hora.refresh(rtc.now());
    Serial.begin(19200);

    setBrightness();

    isUpdateDataWeater = updateDataWeater();
    isUpdateDataFullDate = updateFullDate();


    analogWrite(ligth, 255);
    lcd.cargandoDatos();
    loadAll();
    timeMillis = millis();

    hours = hora.hora;

}


static unsigned long timeSegundosMillis = 0;
static unsigned long timeSegundosMillis2 = 0;
bool primaryLoad = true;
bool hoursLoad = true;


bool checkHora = true;
void loop() {

    if (millis() - timeMillis > 1000) {
        timeMillis = millis();
        fecha.refresh(rtc.now());
        hora.refresh(rtc.now());

        if ((hora.minuto == 0 && hoursLoad) || !isUpdateDataWeater) {
            isUpdateDataWeater = updateDataWeater();
            if (isUpdateDataWeater) {
                hoursLoad = false;
                loadAll();
            }
            Serial.println(isUpdateDataWeater);
            Serial.println(hoursLoad);
        }
        if (hora.minuto == 1) {
            hoursLoad = true;
        }
        lcd.printHora(hora);
    }

    if (millis() - timeSegundosMillis > 60000 || primaryLoad) {
        timeSegundosMillis = millis();
        if ((hora.hora != hours and hora.minuto == 0) || primaryLoad) {
            lcd.printClimaActual(clima, hora);
            hours = hora.hora;
            primaryLoad = false;
            setBrightness();
        }
    }
    if (millis() - timeSegundosMillis > 60000 ) {
        timeSegundosMillis2 = millis();
        if (hora.hora == 0 && hora.minuto == 0 ) {
            isUpdateDataFullDate = false;
        }
        if (!isUpdateDataFullDate) {
            isUpdateDataFullDate = updateFullDate();
            if(isUpdateDataFullDate){
                loadAll();
                setBrightness();
            }
        }
    }

}