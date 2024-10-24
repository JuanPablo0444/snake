#pragma once
class Vector
{
private:
    int x;
    int y;
public:
    Vector(){//Sobrecarga de funciones cuando hay dos funciones con el mismo nombre pero diferente firma
        this -> x= 0;
        this -> y= 0;
    }
    Vector(int x, int y) {//Firma son los parametros
        this ->x = x;
        this ->y = y;
    }
    ~Vector() {}
    int ObtenerX(){
        return this -> x;
    }
    int ObtenerY(){
        return this -> y;
    }
};