/**
 * @file abstraccion.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de clases abstractas
 * @version 0.1
 * @date 2024-11-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Figura {
    protected:
    int base;
    int altura;

    public:
    // getters
    int getBase(){ return this->base; }
    int getAltura() {return this->altura; }

    // setters
    void setBase(int b) { this->base = b; }
    void setAltura(int a) { this->altura = a; }

    // metodos
    virtual int area() = 0;
};

class Rectangulo : public Figura {
    public:
    int area() override {
        return base * altura;
    }

};

class Cuadrado : public Figura {

};

class Triangulo : public Figura {

};


int main()
{
    Rectangulo r;
    r.setAltura(6);
    r.setBase(10);
    cout << r.area() << endl;


    
    return 0;
}
