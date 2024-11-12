/**
 * @file clases.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer clase :>
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

class Rectangulo {
    private:
    int base;
    int altura;

    public:
    // Contructores
    /*Rectangulo() {
        this->altura = 0;
        this->base = 0;
    }*/

    Rectangulo(int altura, int base) {
        this->altura = altura;
        this->base = base;
    }
    ~Rectangulo() {
        cout << "Ya me mori" << endl;
    }

    // GETTERS
    int getBase() {
        return this->base;
    }
    int getAltura() {
        return this->altura;
    }

    // SETTERS
    void setBase(int base) {
        this->base = base;
    }
    void setAltura(int altura) {
        this->altura = altura;
    }

    // Metodo
    int area() {
        return base * altura;
    }
    
};

int main()
{
    Rectangulo rect1(5,6), rect2(6,7);
    

    cout << rect1.area();

    return 0;
}