/**
 * @file abstracto.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Funciones abstractas
 * @version 0.1
 * @date 2024-11-25
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
    void setBase(int b) { this->base = b; }
    void setAltura(int a) { this->altura = a; }

    int getBase() { return this->base; }
    int getAltura() { return this->altura; }

    // Metodo abstracto (funcion virtual pura)
    virtual int area() = 0;
};

class Rectangulo : public Figura{
    public:
    int area() override {
        return this->altura * this->base;
    }
};



int main()
{
    Rectangulo r;
    r.setAltura(5);
    r.setBase(10);
    cout << r.area() ;
    return 0;
}
