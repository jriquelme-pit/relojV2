#define TFT_DC 2
#define TFT_CS 5
#define TFT_RST -1

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

class Lcd{
public:

    Lcd(){
        tft.initR(INITR_BLACKTAB);
    }

    void cargandoDatos(){
        tft.fillScreen(ST7735_BLACK);
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("Cargando informacion...");
    }

    void conectado(String ip){
        tft.fillScreen(ST7735_BLACK);
        tft.setTextColor(ST7735_RED);
        tft.setTextSize(1);
        tft.setCursor(4, 4);
        tft.println("conectado ip ->" + ip);
    }
};
