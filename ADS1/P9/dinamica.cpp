/**
 * @file dinamica.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Dinamica
 * @version 0.1
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
// #include <cstdlib>

using namespace std;

int main()
{
    /*
    // malloc // Pedir memoria dinamica
    // calloc // Pedir memoria dinamica
    // realloc // Realocar memoria dinamica
    // free // Librerar memoria dinamica

    int *entero;
    // entero = (int*)malloc(sizeof(int));
    entero = (int *)calloc(1, sizeof(int));
    cout << entero << endl;
    *entero = 10;
    entero = (int *)realloc(entero, 2 * sizeof(int));
    *(entero + 1) = 11;

    cout << *entero << endl
         << entero << endl
         << *(entero + 1) << endl
         << entero + 1 << endl;
    free(entero);
    */

   int *var = new int;

   delete var; // No arreglos

    int *entero = new int[2];
    *entero = 10;
    *(entero + 1) = 11;

    cout << entero << endl
         << *entero << endl;
    cout << entero + 1 << endl
         << *(entero + 1) << endl;

    delete[] entero; // arreglos

    return 0;
}
