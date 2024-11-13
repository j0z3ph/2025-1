/**
 * @file punteros.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero :>
 * @version 0.1
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int variable = 10;
    int *ptr;
    ptr = &variable;
    double arrg[10];

    cout << variable << endl;
    cout << &variable << endl;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;
    cout << arrg  << endl;
    cout << arrg +1 << endl;
    
    return 0;
}
