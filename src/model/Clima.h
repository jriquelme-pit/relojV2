class Dia{
public:
    int min = 0;
    int max = 0;
    String nombre = "";

};

class Clima{

private:
    Dia hoy;
    Dia siguiente;
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
    void parserJson(String json){
        DynamicJsonBuffer jsonBuffer;
        JsonObject &root = jsonBuffer.parseObject(json);


        hoy.max = root["a"]["1"].as<int>();
        hoy.min = root["a"]["2"].as<int>();
        hoy.nombre = root["day"]["a"].as<String>();

        siguiente.max = root["b"]["1"].as<int>();
        siguiente.min = root["b"]["2"].as<int>();
        siguiente.nombre = root["day"]["b"].as<String>();
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

