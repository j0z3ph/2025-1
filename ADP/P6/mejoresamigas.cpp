/**
 * @file mejoresamigas.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mejores amigas
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Abi {
    private:
    int secreto;
    friend int dameElSecretoDe(Abi a);

    public:
    Abi(){
        secreto = 10;
    }
};

int dameElSecretoDe(Abi a){
    return a.secreto;
}

int main()
{
    Abi a;

    cout << dameElSecretoDe(a);
    
    
    return 0;
}
