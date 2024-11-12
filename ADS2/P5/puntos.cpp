/**
 * @file puntos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segunda clase :>
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
    Punto(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // Getters
    int getX() { return this->x; }
    int getY() { return this->y; }

    // Setters
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
};

ostream &operator<<(ostream &os, Punto &p)
{
    os << "(" << p.getX() << "," << p.getY() << ")";
    return os;
}

Punto operator+(Punto &p1, Punto &p2)
{
    Punto res(0, 0);
    res.setX(p1.getX() + p2.getX());
    res.setY(p1.getY() + p2.getY());
    return res;
}

int main()
{
    Punto p1(4, 5), p2(5, 6);
    ++p1;
    p1++;
    Punto p3 = p1 + p2;
    cout << p3;

    return 0;
}