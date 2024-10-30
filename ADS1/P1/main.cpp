/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer programa en C++ :>
 * @version 0.1
 * @date 2024-10-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#define CONSTANTE2 100

using namespace std;

int main()
{
    int variable = 10;
    const int CONSTANTE = 5;
    string nombre;

    cout << "Usuario, ingresa un entero positivo: ";
    cin >> variable;

    cout << "El doble de " << variable
         << " es " << 2 * variable << "." << endl;
    while (getc(stdin) != '\n');
    getline(cin, nombre);
    cout << nombre << endl;

    return 0;
}
