/**
 * @file promedio.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Pide al usuario 5 numeros y devuelve su promedio
 * @version 0.1
 * @date 2024-10-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

int main()
{
    float numero = 0;
    float suma = 0;
    float promedio = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        cout << "Usuario, ingresa un numero: ";
        cin >> numero;
        suma += numero;
    }
    promedio = suma / 5;

    cout << "El promedio es: " << promedio << endl;

    return 0;
}
