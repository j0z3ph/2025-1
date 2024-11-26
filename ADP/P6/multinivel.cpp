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
#include <iostream>

using namespace std;

class Madre {
    public:
    void metodo(){}
};
class Hija: public Madre {
    public:
    void metodoHija() {}
};

class Nieto : public Hija {
    public:
    void metodoNieto() {}
};

int main()
{
    Nieto n;
    
    
    return 0;
}
