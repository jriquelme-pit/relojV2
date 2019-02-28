class HoraClima{
public:
    int temp = 0;
    int windchill = 0;
    String desc = "";

};


class Dia{
public:
    int min = 0;
    int max = 0;
    String nombre = "";

    String toString(){
        return String(min)  + " - " + String(max) + nombre;
    };

};

class Clima{

private:
    Dia hoy;
    Dia siguiente;
    HoraClima horaClima[25] ;
public:

    Clima(){
        hoy = Dia();
        siguiente = Dia();
    }

    Dia getHoy(){
        return hoy;
    }
    Dia getSiguiente(){
        return siguiente;
    }
    HoraClima getHoraClima(int hour){
        return horaClima[hour];
    }
    void parserJson(String json){
        DynamicJsonBuffer jsonBuffer;

        Serial.println(json);
        JsonObject &root = jsonBuffer.parseObject(json);


        hoy.min = root["a"]["1"].as<int>();
        hoy.max = root["a"]["2"].as<int>();
        hoy.nombre = root["day"]["a"].as<String>();

        siguiente.min = root["b"]["1"].as<int>();
        siguiente.max = root["b"]["2"].as<int>();
        siguiente.nombre = root["day"]["b"].as<String>();


        for (int i = 0; i < 24; ++i) {
            horaClima[i] = HoraClima();
            horaClima[i].temp = root["hour"][String(i+1)]["temp"].as<int>();
            horaClima[i].windchill = root["hour"][String(i+1)]["windchill"].as<int>();
            horaClima[i].desc = root["hour"][String(i+1)]["desc"].as<String>();
        }

    }

    void dummy(){


        hoy.max = 21;
        hoy.min = 12;
        hoy.nombre = "Sabado";

        siguiente.max = 34;
        siguiente.min = 20;
        siguiente.nombre = "Domingo";
    }

};

