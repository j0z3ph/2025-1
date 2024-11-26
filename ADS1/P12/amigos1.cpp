/**
 * @file amigos1.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Funciones amigas
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Caeri {
    private:
    int numeroDeLaSuerte = 9;
    friend int dameElNumeroDeLaSuerteDe(Caeri c);
};


int dameElNumeroDeLaSuerteDe(Caeri c) {
    return c.numeroDeLaSuerte;
}

int main()
{
    Caeri c;


    cout << dameElNumeroDeLaSuerteDe(c);
    
    return 0;
}
