/**
 * @file funciones.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer funcion :>
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include "lazaro.hpp"

using namespace std;
using namespace jose;

int main()
{ 
    cout << suma(5,7) << endl;

    cout << suma(5.6f, 6.7f) << endl;

    cout << suma(5,6,7) << endl;
    
    return 0;
}

