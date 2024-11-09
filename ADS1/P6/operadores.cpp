/**
 * @file operadores.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer sobre carga de operadores
 * @version 0.1
 * @date 2024-11-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Punto {
    private:
    int x;
    int y;

    public:
    Punto(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return this->x; }
    int getY() { return this->y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    void operator ++() {
        this->x++;
        this->y++;
    }
};


int main()
{
    Punto a(4,5);
    ++a;
    cout << a.getX() << "," << a.getY() << endl;

    
    return 0;
}
