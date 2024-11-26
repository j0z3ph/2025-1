/**
 * @file amigos2.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Clases amigas
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class A {
    private:
    int secreto;
    friend class B;

    public:
    A() {
        secreto = 666;
    }

    int dameElSecretoDeB() {
        B b;
        return b.secretoMasSecreto;
    }
};

class B {
    private:
    int secretoMasSecreto;

    public:
    B() {
        secretoMasSecreto = 999;
    }
    int dameElSecretoDeA() {
        A a;
        return a.secreto;
    }
};

int main()
{
    B b;
    A a;
    cout << b.dameElSecretoDeA() << endl;
    
    
    return 0;
}
