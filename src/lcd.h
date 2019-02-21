



#define TFT_DC 2
#define TFT_CS 5
#define TFT_RST -1

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

class Lcd{
private:

public:

    Lcd(){
        tft.initR(INITR_BLACKTAB);
    }

    void cargandoDatos(){
        clear();
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("Cargando informacion...");
    }

    void conectado(String ip){
        clear();
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("conectado ip ->" + ip);
    }

    void printFecha(Fecha fecha){
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(2);
        tft.setCursor(2, 2);
        tft.println(fecha.toString());
    }

    void printHora(Hora hora){
        tft.setTextColor(ST7735_WHITE);
        tft.setTextSize(4);
        tft.setCursor(2, 20);
        tft.println(hora.toString());
    }

    void clear(){
        tft.fillScreen(ST7735_BLACK);
    }

};


