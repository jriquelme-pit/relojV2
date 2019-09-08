class Hora{
private:

public:
    int hora = 0;
    int minuto = 0;
    int segundos = 0;

    Hora(){

    }

    String toString(boolean printHora = true){

        String spe = " ";
        if(printHora){
          spe = ":";
        };
        return zero(String(this->hora), 2) + spe + zero(String(this->minuto), 2);
    }

    void setData(String Data){
        DynamicJsonBuffer jsonBuffer;
        JsonObject &root = jsonBuffer.parseObject(Data);

        hora = root["hours"].as<int>();
        minuto =  root["minutes"].as<int>();

    }

    void refresh(DateTime now){
        this->minuto = now.minute();
        this->hora = now.hour();
    }
    int getCiclo(){

        if(hora >= 2 && hora < 5 ) return 0;
        if(hora >= 5 && hora < 8 ) return 1;
        if(hora >= 8 && hora < 11 ) return 2;
        if(hora >= 11 && hora < 14 ) return 3;
        if(hora >= 14 && hora < 17 ) return 4;
        if(hora >= 17 && hora < 20 ) return 5;
        if(hora >= 20 && hora < 23 ) return 6;
        if(hora >= 23 ) return 7;
    }
};