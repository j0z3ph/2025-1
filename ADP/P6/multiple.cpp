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
#include<iostream>

using namespace std;

class Mama {
    public:
    void habla() {
        cout << "Y si yo lo encuentro que te hago?";
    }
};
class Papa {
    public:
    void habla() {
        cout << "Voy al OXXO por cigarros";
    }
};
class Jon : public Mama, public Papa {

};

int main()
{
    Jon j;
    j.Mama::habla();
    
    return 0;
}
