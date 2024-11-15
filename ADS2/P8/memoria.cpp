/**
 * @file memoria.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Memoria dinamica
 * @version 0.1
 * @date 2024-11-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{

    // int *entero = (int *)malloc(4);
    int *entero = (int *)calloc(1, sizeof(int));
    *entero = 10;

    cout << entero << endl;

    entero = (int *)realloc(entero, 20000 * sizeof(int));

    *(entero + 1) = 11;

    cout << entero << endl
         << *entero << endl
         << entero + 1 << endl
         << entero[1] << endl;

    free(entero);

    return 0;
}
