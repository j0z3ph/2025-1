/**
 * @file funciones.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Paso de referencia
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

/// @brief Paso por valor
/// @param a 
/// @param b 
/// @return 
int suma(int a, int b) {
    int c;
    c = a + b;
    return c;
}

int suma_ref(int *a, int *b) {
    int c;
    c = *a + *b;
    return c;
}

int suma_ref_chida(int &a, int &b) {
    int c;
    c = a + b;
    return c;
}


int main()
{
    int a = 10;
    int b = 5;
    cout << suma_ref_chida(a,b) << endl;
    
    return 0;
}
