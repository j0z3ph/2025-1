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
#define CONSTANTE2 10

using namespace std;

int main()
{
    int variable = 10;
    string nombre;

    cout << "Usuario, escribe un numero entero positivo: ";
    cin >> variable;
    cout << "El cuadrado de " << variable << " es "
         << variable * variable << "." << endl;
    while (getc(stdin) != '\n');
    getline(cin, nombre);
    cout << nombre;

    return 0;
}
