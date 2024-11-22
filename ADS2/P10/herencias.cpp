/**
 * @file herencias.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Modos de acceso en herencia
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Figura{
    private:
    int privado;
    protected:
    int base;
    int altura;
    public:
    void setAltura(int a) { this->altura = a; }
    void setBase(int a) { this->base = a; }

    int getAltura() {return this->altura; }
    int getBase() {return this->base; }
};

class Rectangulo : public Figura {
};

class Cuadrado : protected Figura {
};

class Triangulo : private Figura {
};



int main()
{
    Figura f;
    Rectangulo r;
    Cuadrado c;
    Triangulo t;
    
    
    return 0;
}
