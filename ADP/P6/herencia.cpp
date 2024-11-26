/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer herencia
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class Figura {
    protected:
    int base;
    int altura;

    public:
    // getters
    int getBase() { return this->base; }
    int getAltura() { return this->altura; }

    // setters
    void setBase(int b) { this->base = b; }
    void setAltura(int a) { this->altura = a;}

    // Metodos
    virtual int area() = 0;
};

class Rectangulo : public Figura {
    public:
    // Sobreescritura de funciones
    int area() override {
        return base * altura;
    }
    // Sobrecarga de funciones
    int area(int a) {
        return base * altura * a;
    }

};

class Cuadrado: public Figura {

};

class Triangulo : public Figura {

};


int main()
{
    
    Rectangulo r;
    Cuadrado c;
    
    r.setAltura(10);
    r.setBase(5);

    cout << r.area() << endl;
    cout << r.Figura::area();
   
    
    
    
    return 0;
}
