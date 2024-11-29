/**
 * @file archivos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-11-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int entero = 500;
    
    fstream archib("archivo.bin", ios::binary | ios::in);

    archib.read((char *)&entero, sizeof(int));

    cout << entero;

    archib.close();

    return 0;

    ofstream archi("archivo.txt");
    string cadena;
    double doble;
    if (!archi.is_open())
    {
        ofstream archi2("archivo.txt");
        if (!archi2.is_open())
        {
            cout << "Ups, no fue posible abrir el archivo." << endl;
            return 1;
        }
        archi2.close();
    }

    archi << "Holi " << 5 << " " << 10.5;

    // archi >> cadena;
    // archi >> entero;
    // archi >> doble;

    // cout << cadena << entero << doble;

    // while(!archi.eof()) {
    //     getline(archi, cadena);
    //     cout << cadena << endl;
    // }




    archi.close();

    return 0;
}
