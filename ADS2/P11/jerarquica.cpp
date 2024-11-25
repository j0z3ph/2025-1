/**
 * @file jerarquica.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia jerarquica
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class Mama {
    protected:
    int a;

    public:
    void set(int a) { this->a = a; }
    int get() { return this->a; }
};
class HijoBueno : public Mama {

};
class HijoMalo : public Mama {

};

int main()
{
    HijoMalo m;
    HijoBueno b;
    
    
    return 0;
}
