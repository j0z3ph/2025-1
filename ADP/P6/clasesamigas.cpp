/**
 * @file clasesamigas.cpp
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

class Paola {
    private:
    string maximoSecreto;
    friend class Abi;
    public:
    Paola() {
        maximoSecreto = "Odio a Abi";
    }

    string chisme() {
        Abi a;
        return a.maximoSecreto;
    }

};

class Abi {
    private:
    string maximoSecreto;

    public:
    Abi() {
        maximoSecreto = "Tiene 10 novios y 10 amantes";
    }

    string chisme() {
        Paola p;
        return p.maximoSecreto;
    }


};

int main()
{
    Abi a;

    cout << "Chismesito: " << a.chisme() ;
    
    return 0;
}
