class Fecha{
private:
    long dia = 0;
    long mes = 0;
    long anno = 0;

public:
    Fecha(){

    }
    String toString(){
        return zero(String(this->dia), 2) + "-" + zero(String(this->mes), 2) + "-" + zero(String(this->anno), 4);
    }

};