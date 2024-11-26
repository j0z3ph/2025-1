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

class Matriarca {
    public:
    void metodo() {}
};

class HijaMala : public Matriarca {

};
class HijaBuena: public Matriarca {

};

int main()
{
    HijaBuena paola;
    HijaMala abi;
    
    return 0;
}
