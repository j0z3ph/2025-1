/**
 * @file parametros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int suma(int a, int b) {
    int c;
    c = a - b;
    return c;
}

int suma_ref(int *a, int *b) {
    int c;
    c = *a - *b;
    return c;
}

int suma_ref_chido(int &a, int &b) {
    int c;
    c = a - b;
    return c;
}


int main()
{
    int a = 10, b = 9;
    cout << suma_ref_chido(a,b) << endl;

    int *entero = new int;
    delete entero;

    int *arr = new int[10];
    delete[] arr;

    
    return 0;
}
