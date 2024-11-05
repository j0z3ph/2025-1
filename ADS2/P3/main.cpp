/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int arreglo[100];
    list<int> lista2;
    vector<int> lista;

    lista2.push_back(5);
    lista2.push_back(10);

    for (auto &&i : lista2)
    {
        cout << i << " ";   
    }
    

    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.emplace_back(7);

    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << " ";
    }
    
    
    
    return 0;
}
