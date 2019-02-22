class Hora{
private:

public:
    int hora = 0;
    int minuto = 0;

    Hora(){

    }

    String toString(boolean printHora){

        String spe = " ";
        if(printHora){
          spe = ":";
        };
        return zero(String(this->hora), 2) + spe + zero(String(this->hora), 2);
    }

    void setData(String Data){
        DynamicJsonBuffer jsonBuffer;
        JsonObject &root = jsonBuffer.parseObject(Data);

        hora = root["hours"].as<int>();
        minuto =  root["minutes"].as<int>();


    }
};