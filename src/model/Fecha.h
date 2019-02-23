class Fecha{
private:
    long dia = 0;
    long mes = 0;
    long annio = 0;

public:
    Fecha(){

    }
    String toString(){
        return zero(String(this->dia), 2) + "-" + zero(String(this->mes), 2) + "-" + zero(String(this->annio), 4);
    }

    void refresh(DateTime now){
        this->dia = now.day();
        this->mes = now.month();
        this->annio = now.year();
    }

};