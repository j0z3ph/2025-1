/**
 * @file clases.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer clase :>
 * @version 0.1
 * @date 2024-11-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

typedef int entero;

typedef struct Rect
{
    int base;
    int altura;

    int area()
    {
        return base * altura;
    }
} Rect;

class Rectangulo
{
private:
    int base;
    int altura;

public:
    void setBase(int base)
    {
        this->base = base;
    }
    int getBase()
    {
        return this->base;
    }

    void setAltura(int altura)
    {
        this->altura = altura;
    }
    int getAltura()
    {
        return this->altura;
    }

    int area()
    {
        return base * altura;
    }
};

int main()
{
    entero variable;
    struct Rect r;
    Rectangulo rect;
    
    rect.setBase(5);
    rect.setAltura(10);
    cout << rect.area() << endl;

    r.altura = 10;
    r.base = 5;

    return 0;
}