/**
 * @file amigos1.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Funciones amigas
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

class IanEduardo {
    private:
    int alan = 10;
    friend int getMejorAmigo(IanEduardo ie);
};

int getMejorAmigo(IanEduardo ie) {
    return ie.alan;
}

int main()
{
    IanEduardo ie;
    

    cout << getMejorAmigo(ie) << endl;
    
    
    return 0;
}
