/**
 * @file programa.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer constructor
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

class Punto
{
private:
    int x;
    int y;

public:
    // Contructor por defecto
    Punto()
    {
        // cout << "Ya naci" << endl;
        this->x = 0;
        this->y = 0;
    }
    Punto(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // Destructor
    ~Punto()
    {
        // cout << "Ya me mori" << endl;
    }

    // getters
    int getX() { return this->x; }
    int getY() { return this->y; }

    // setters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Sobrecarga de operadores
    void operator++()
    {
        this->x++;
        this->y++;
    }
    void operator++(int)
    {
        this->x++;
        this->y++;
    }
    friend ostream &operator<<(ostream &os, Punto &p)
    {
        os << "(" << p.getX() << "," << p.getY() << ")";
        return os;
    }
};

Punto operator+(Punto &a, Punto &b)
{
    Punto c(0, 0);
    c.setX(a.getX() + b.getX());
    c.setY(a.getY() + b.getY());
    return c;
}

int main()
{
    Punto p1(10, 11), p2(5, 6), p3;
    Punto r = p1 + p2;
    int a = 10;
    ++a;
    ++p1;
    p1++;

    cout << r << endl;

    return 0;
}
