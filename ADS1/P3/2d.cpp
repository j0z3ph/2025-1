/**
 * @file 2d.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer matriz :>
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int matriz[3][3];
    int cont = 0;

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            matriz[fila][columna] = ++cont;
        }
    }
    
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            cout << matriz[columna][fila] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
