/**
 * @file archivos.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de archivos de texto
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
    fstream archi("archivo.txt", ios::in | ios::out);
    string linea;
    int entero;
    float flotante;
    
    if (!archi.is_open())
    {
        ofstream archi2("archivo.txt");
        if (!archi2.is_open())
        {
            cout << "Upsss, no existe el archivo :<" << endl;
            return 1;
        }
        archi2.close();
    }

    archi << "Holi canoli....." << endl;

    archi.seekg(ios::beg + 16);

    getline(archi, linea);

    cout << linea;


    // archi << "Hola ";
    // archi << 666 << " ";
    // archi << 666.999 << endl;

    // archi >> linea;
    // archi >> entero;
    // archi >> flotante;

    // cout << linea << entero << flotante;

    // while(!archi.eof()) {
    //     getline(archi, linea);
    //     cout << linea << endl;
    // }
    



    return 0;
}
