/**
 * @file simple.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia simple
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class A {
    protected:
    int a;
    public:
    void set(int a) { this->a = a; }
    int get() { return this->a; } 
};

class B : public A {};


int main()
{
    B b;
    
    
    return 0;
}
