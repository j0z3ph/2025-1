/**
 * @file multiple.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Herencia multiple
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class Mama {
    public:
    void habla() {
        cout << "Y si lo encuentro yo, que te hago?";
    }
};

class Papa {
    public:
    void habla() {
        cout << "Ir al OXXO por un cigarro";
    }
};

class Hija : public Mama, public Papa {

};

int main()
{
    Hija h;

    h.Papa::habla();
    
    return 0;
}
