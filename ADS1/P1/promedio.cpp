/**
 * @file promedio.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Pide al usuario n numeros y devuelve su promedio
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
    int n = 0;
    cout << "Usuario, cuantos numeros quieres? ";
    cin >> n;
    if (n <= 0)
    {
        cout << "No seas tonto >:|" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Usuario, ingresa un numero: ";
        cin >> numero;
        suma += numero;
    }
    promedio = suma / (float)n;

    cout << "El promedio es: " << promedio << endl;

    return 0;
}
