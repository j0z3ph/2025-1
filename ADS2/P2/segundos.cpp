/**
 * @file segundos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Convierte una cantidad de segunos a HH:MM:SS
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
    int entero = 0;
    int horas = 0, minutos = 0, segundos= 0;
    cout << "Usuario, ingrese un numero entero positivo: ";
    cin >> entero;

    if(entero < 0) 
    {
        cout << "No seas tonto, dije POSITIVO >:c" << endl;
        return 1;
    }

    horas = entero / 3600;
    entero %= 3600;
    minutos = entero / 60;
    segundos = entero % 60;

    printf("%02i:%02i:%02i\n", horas, minutos, segundos);

    return 0;
}