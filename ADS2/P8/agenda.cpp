/**
 * @file agenda.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer agenda :>
 * @version 0.1
 * @date 2024-11-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include "tools.hpp"

using namespace std;
using namespace tools;

int main()
{
    vector<string> opciones;
    int opc;
    opciones.push_back("Agregar contacto");
    opciones.push_back("Llamar contacto");
    opciones.push_back("Listar contactos");
    opciones.push_back("Salir");

    opc = showMenu(opciones, "Agenda de Contactos");

    cout << opc << endl;
    
    return 0;
}
