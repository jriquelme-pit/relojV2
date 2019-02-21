class Hora{
private:
    int hora = 0;
    int minuto = 0;

public:
    Hora(){

    }

    String toString(){
        return zero(String(this->hora), 2) + ":" + zero(String(this->hora), 2);
    }
};