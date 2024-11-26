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

class Madre {
    protected:
    int a;

    public:
    void madre() {}
};

class Hija : public Madre {
    protected:
    int b;

    public:
    void hija() {}
};

class Nieta : public Hija {

};


int main()
{
    Nieta n;
    
    
    return 0;
}

