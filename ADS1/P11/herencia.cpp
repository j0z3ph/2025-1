/**
 * @file herencia.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa con herencia
 * @version 0.1
 * @date 2024-11-22
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
    int getBase() { return this->base; }
    int getAltura() {return this->altura; }

    // setters
    void setBase(int base) { this->base = base; }
    void setAltura(int altura) { this->altura = altura; }

    // Metodos
    int area() {
        return 0;
    }
};

class Rectangulo : public Figura 
{
    public:
    int area() {
        return base * altura;
    }
    
};


class Cuadrado : public Figura 
{
    public:

    int area() {
        return base * base;
    }
    
};


class Triangulo : public Figura 
{
    public: 
    // Sobre escritura
    int area() {
        return (base * altura) / 2;
    }

    // Sobre carga
    int area(int a) {
        return a;
    }
    
};



int main()
{
    Rectangulo r;
    Cuadrado c;
    Triangulo t;

    r.setAltura(5);
    r.setBase(2);

    cout << r.area() << endl;
    cout << r.Figura::area() ;

    return 0;
}
