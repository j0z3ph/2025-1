/**
 * @file funciones.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa con funciones
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <cmath>
#include "bibfunciones.hpp"

using namespace std;
using namespace telematica;

int main()
{
    int a = 0, b = 0;

    cout << "Usuario, ingrese un numero: ";
    cin >> a;
    cout << "Ahora ingrese otro numero: ";
    cin >> b;
 
    cout << "La suma de " << a << " mas " << b << " es " << suma(a, b) << endl;
    imprime(suma(a, b));

    cout << endl << suma(6.7f, 8.8f);

    cout << endl << suma(4,5,6);


    return 0;
}
