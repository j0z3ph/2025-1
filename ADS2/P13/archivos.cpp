/**
 * @file archivos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer archivo
 * @version 0.1
 * @date 2024-11-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream archi("archi.txt", ios::in | ios::out);
    string linea;
    int numero;
    float flotante;
    if (!archi.is_open())
    {
        ofstream archi2("archi.txt");
        if (!archi2.is_open())
        {
            cout << "Upss, no fue posible crear el archivo :<" << endl;
            return 1;
        }
        archi2.close();
    }

    archi << "HolA MundO :>" << endl;

    archi.seekg(ios::beg + 2);

    getline(archi, linea);


    cout << linea;

    //archi >> linea;
    //archi >> numero;
    //archi >> flotante;

    //cout << linea << numero << flotante ;
    
    //while(!archi.eof()) {
        //getline(archi, linea);
    //     archi >> linea;
    //     cout << linea << endl;
    // }

    archi.close();

    return 0;
}
