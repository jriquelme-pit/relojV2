


#define TFT_DC 2
#define TFT_CS 16
#define TFT_RST -1

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

class Lcd {
private:

public:

    boolean separador = true;


    Lcd() {
        tft.initR(INITR_BLACKTAB);
    }

    void printPlantilla() {
        tft.drawLine(0, 18, tft.height() - 1, 18, ST77XX_GREEN);
        tft.drawLine(0, 54, tft.height() - 1, 54, ST77XX_GREEN);
        tft.drawLine(tft.width() / 2, 54, tft.width() / 2, 105, ST77XX_GREEN);
        tft.drawLine(0, 105, tft.height() - 1, 105, ST77XX_GREEN);

    }

    void cargandoDatos() {
        clear();
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("Cargando informacion...");
    }

    void conectado(String ip) {
        clear();
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("conectado ip ->" + ip);
    }

    void printFecha(Fecha fecha) {

        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.setTextSize(2);
        tft.setCursor(5, 2);
        tft.println(fecha.toString());
    }

    void printHora(Hora hora) {
        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.setTextSize(4);
        tft.setCursor(5, 22);
        tft.println(hora.toString(separador));
        this->separador = !this->separador;
    }

    void clear() {
        tft.fillScreen(ST7735_BLACK);
    }

    void printClima(Clima clima) {

        tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
        tft.setTextSize(1);
        tft.setCursor(2, 57);
        tft.println(clima.getHoy().nombre);
        tft.setCursor(70, 57);
        tft.println(clima.getSiguiente().nombre);

        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.setCursor(2, 68);
        tft.println("min:");
        tft.setTextSize(2);
        tft.setCursor(25, 68);
        tft.println(clima.getHoy().min);
        tft.setTextSize(1);
        tft.setCursor(48, 68);
        tft.println("c");

        tft.setTextSize(1);
        tft.setCursor(70, 68);
        tft.println("min:");
        tft.setTextSize(2);
        tft.setCursor(93, 68);
        tft.println(clima.getSiguiente().min);
        tft.setTextSize(1);
        tft.setCursor(118, 68);
        tft.println("c");

        tft.setTextSize(1);
        tft.setCursor(2, 85);
        tft.println("max:");
        tft.setTextSize(2);
        tft.setCursor(25, 85);
        tft.println(clima.getHoy().max);
        tft.setTextSize(1);
        tft.setCursor(48, 85);
        tft.println("c");

        tft.setTextSize(1);
        tft.setCursor(70, 85);
        tft.println("max:");
        tft.setTextSize(2);
        tft.setCursor(93, 85);
        tft.println(clima.getSiguiente().max);
        tft.setTextSize(1);
        tft.setCursor(118, 85);
        tft.println("c");


    }

    void clearTest(String text) {

        tft.setTextSize(4);
        tft.setCursor(5, 22);
        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.println(text);

    }

    void printClimaActual(Clima clima, Hora hora){
        /*tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);

        tft.setTextSize(1);
        tft.setCursor(2, 110);
        tft.println("today:");

        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.setTextSize(2);

        tft.setCursor(38, 110);
        HoraClima clima1 = clima.getHoraClima(hora.hora);
        tft.println(clima1.temp);

        tft.setTextSize(1);
        tft.setCursor(65, 110);
        tft.println("c");

*/
        HoraClima clima1 = clima.getHoraClima(hora.hora);
        tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
        tft.setTextSize(1);
        tft.setCursor(2, 110);
        tft.println("windchill:");

        tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
        tft.setTextSize(2);
        tft.setCursor(65, 110);
        tft.println(clima1.temp);
        Serial.println(clima1.temp);

        tft.setTextSize(1);
        tft.setCursor(95, 110);
        tft.println("c");

        tft.setTextSize(2);
        tft.setTextWrap(true);
        tft.setCursor(2, 128);
        tft.println(clima1.desc);


    };

};


