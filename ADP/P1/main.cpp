/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa en C++ :>
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int entero = 0;
    string cadena;
    cout << "Usuario, ingresa un numero: ";
    cin >> entero;

    while (getc(stdin) != '\n');

    cout << "Otra cadena: ";
    getline(cin, cadena);

    cout << cadena << endl;

    cout << "El entero es " << entero << ".\n";
    return 0;
}
