/**
 * @file multinivel.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia multinivel
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Principal {
    protected:
    int principal;

    public:
    void set(int a) { this->principal = a; }
    int get() { return this->principal; }
};

class Hija : public Principal {
    protected:
    int hija;

    public:
    void setH(int h) { this->hija = h; }
    int getH() { return this->hija; }
};

class Nieto: public Hija {
    protected:
    int nieto;

    public:
    void setN(int n) { this->nieto = n; }
    int getN() { return this->nieto; }
};

int main()
{
    Nieto n;
    
    
    return 0;
}
