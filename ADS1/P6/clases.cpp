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
#include<iostream>

using namespace std;

typedef int entero;

typedef struct Rect {
    int base;
    int altura;
    int area() {
        return base * altura;
    }
} Rect;

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
    Rectangulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }
    // Destructor
    ~Rectangulo() {
        cout << "Ya me mori :<" << endl;
    }


    // SETTERS
    void setBase(int base) {
        this->base = base;
    }
    void setAltura(int altura) {
        this->altura = altura;
    }

    // GETTERS
    int getBase() {
        return this->base;
    }
    int getAltura() {
        return this->altura;
    }


    // METODOS
    int area() {
        return base * altura;
    }
};

int main()
{
    entero variable;
    Rect rect1;
    rect1.altura = 10;
    rect1.base = 10;

    Rectangulo rect2(10,10);
    //rect2.setAltura(10);
    //rect2.setBase(10);
    cout << rect2.area();

    
    return 0;
}
