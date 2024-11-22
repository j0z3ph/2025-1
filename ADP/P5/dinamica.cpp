/**
 * @file dinamica.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Memoria dinamica
 * @version 0.1
 * @date 2024-11-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int *puntero = new int;
    *puntero = 10;

    cout << *puntero << " - " << puntero << endl;

    // Reallocacion
    int *tmp = new int[2];
    memcpy(tmp, puntero, sizeof(int));
    *(tmp+1) = 11;
    delete puntero;
    puntero = tmp;

    cout << *puntero << " - " << puntero << endl;
    cout << *(puntero+1) << " - " << puntero+1 << endl;

    delete[] tmp;
    
    return 0;
}
