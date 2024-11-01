/**
 * @file dias.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Convierte un numero de dias en AA,MM,DD
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
    int dias = 0;
    int anio = 0, mes = 0, dia = 0;
    cout << "Usuario, ingrese un numero entero: ";
    cin >> dias;

    anio = dias / 365;
    dias %= 365;
    mes = dias / 30;
    dia = dias % 30;

    printf("%02i,%02i,%02i\n", anio, mes, dia);

    return 0;
}
