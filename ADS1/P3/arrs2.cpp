/**
 * @file arrs2.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mas arreglos
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
    int a;
    vector<int> lista;
    list<int> vect;

    vect.push_back(10);
    vect.push_back(55);
    vect.push_back(5);

    for (auto &&i : vect)
    {
        cout << i << " ";
    }
    cout << endl;
    
    



    lista.push_back(3);
    lista.push_back(10);
    lista.push_back(100);

    lista.emplace_back(101);

    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << " ";
    }
    

    return 0;
}
