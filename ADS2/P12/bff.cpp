/**
 * @file bff.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Clases amigas
 * @version 0.1
 * @date 2024-11-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class Ian {
    private:
    string secreto;
    friend class Alan;
    public:

    Ian() {
        secreto = "Alan es mi mejor amigo <3";
    }

    string chismesito(){
        Alan a;
        return a.secreto;
    }
};

class Alan {
    private:
    string secreto;

    public: 
    Alan() {
        secreto = "Odio a Ian >:(";
    }

    string chismesito() {
        Ian i;
        return i.secreto; 
    }
};

int main()
{
    Ian i;
    Alan a;

    cout << a.chismesito() ;
    
    
    return 0;
}
