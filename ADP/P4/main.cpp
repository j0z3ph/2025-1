/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero :>
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

int main()
{
    int variable_normal = 10;
    int *ptr;
    ptr = &variable_normal;

    cout << ptr << endl;
    cout << *ptr << endl;
    
    return 0;
}
