/**
 * @file jerarquica.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia jerarquica
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

class Patriarca {
    protected:
    int a;

    public:
    void metodo() {}
};

class HijaBueno : public Patriarca {

};

class HijaMala : public Patriarca {

};

int main() {
    HijaBueno b;
    HijaMala m;

    

    return 0;
}