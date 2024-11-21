#include "ejemplobib.hpp"


// Setters
void Figura::setBase(int base) { this->base = base; }
void Figura::setAltura(int altura) { this->altura = altura; }

// Getters
int Figura::getBase() { return this->base; }
int Figura::getAltura() { return this->altura; }

// Metodos
int Figura::area()
{
    return this->base * this->altura;
}

int Figura::perimetro()
{
    return 2 * base + 2 * altura;
}
