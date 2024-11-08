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

struct Rect {
    int base;
    int altura;

    int area() {
        return base * altura;
    }
};

class Rectangulo {
    private:
    int base;
    int altura;

    public:
    // Contructores
    Rectangulo() {
        this->altura = 0;
        this->base = 0;
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
    struct Rect rect;
    rect.altura = 10;
    rect.base = 11;

    Rectangulo rect1;
    
    //rect1.setAltura(10);
    //rect1.setBase(10);
    cout << rect1.area();

    return 0;
}