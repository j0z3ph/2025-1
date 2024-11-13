/**
 * @file parametros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Paso de parametros
 * @version 0.1
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int suma(int a, int b);

int suma_ref(int *a, int *b);

int suma_ref_chida(int &a, int &b);

int main()
{
    int a = 10, b = 11, c;
    c = suma_ref_chida(a, b);
    cout << c << endl;
    cout << a << endl;
    cout << b << endl;
    
    return 0;
}


int suma(int a, int b) {
    int c;
    c = a + b;
    a = 999;
    b = 666;
    return c;
}

int suma_ref(int *a, int *b) {
    int c;
    c = *a + *b;
    *a = 999;
    *b = 666;
    return c;
}

int suma_ref_chida(int &a, int & b) {
    int c;
    c = a + b;
    a = 999;
    b = 666;
    return c; 
}