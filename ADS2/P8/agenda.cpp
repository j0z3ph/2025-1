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
#include <iostream>
#include "tools.hpp"
#include "agendalib.hpp"

using namespace std;
using namespace tools;
using namespace agenda;

int main()
{
    vector<string> opciones;
    Agenda agenda;
    int cont = 1;
    int opc;
    opciones.push_back("Agregar contacto");
    opciones.push_back("Llamar contacto");
    opciones.push_back("Listar contactos");
    opciones.push_back("Salir");

    do
    {
        opc = showMenu(opciones, "Agenda de Contactos");

        if (opc == 0)
        {
            // Agregar
            string nombre,apodo,telefono;
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);
            cout << "Ingrese el apodo: ";
            getline(cin, apodo);
            cout << "Ingrese el telefono: ";
            getline(cin, telefono);
            Contacto c(nombre, telefono, apodo);

            agenda.agregar(c);
        }
        if(opc == 1) {
            // Llamar
            int contactoId = showMenu(agenda.listaContactos(), "Seleccione un contacto");
            cout << agenda.llamarContacto(contactoId) << endl;
        }
        if (opc == 2)
        {
            // Listar
            cout << agenda.listar();
        }

        pausa();
    } while (opc != 3);

    return 0;
}
