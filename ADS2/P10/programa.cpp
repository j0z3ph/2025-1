/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de getters y setters
 * @version 0.1
 * @date 2024-11-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include "ejemplobib.hpp"

using namespace std;


int main() 
{
    Rectangulo rect(5, 6);
    Cuadrado c(5,6);
    Triangulo t(4,5);

    cout << rect.getAltura() << "," << rect.getBase() << endl;

    // rect.setBase(5);
    // rect.setAltura(10);

    cout << rect.getAltura() << " x " << rect.getBase() << endl;
    cout << "El area es: " << rect.area() << " y su perimetro es "
         << rect.perimetro() << endl;

    return 0;
}

