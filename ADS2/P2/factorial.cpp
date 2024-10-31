/**
 * @file factorial.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Calcula el factorial de un numero proporcionado por el usuario
 * @version 0.1
 * @date 2024-10-31
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    int numero = 0, factorial = 1;
    cout << "Usuario, ingrese un numero: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }

    cout << "El factorial de " << numero << " es " << factorial << endl;

    return 0;
}
