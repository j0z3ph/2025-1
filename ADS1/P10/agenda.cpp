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
#include <vector>
#include "tools.hpp"
#include "contactolib.hpp"

using namespace std;
using namespace tools;
using namespace agenda;

int main()
{
    Agenda agenda;
    vector<string> opciones;
    int cont = 1;
    int opc;
    opciones.push_back("Agregar contactor");
    opciones.push_back("Llamar contacto");
    opciones.push_back("Listar contactos");
    opciones.push_back("Salir");

    do
    {
        opc = showMenu(opciones, "AGENDA DE CONTACTOS");

        if (opc == 0)
        {
            string nombre;
            string numero;
            string correo;
            string apodo;
            cout << "Ingrese el nombre: ";
            getline(cin, nombre);
            cout << "Ingrese el numero: ";
            getline(cin, numero);
            cout << "Ingrese el correo: ";
            getline(cin, correo);
            cout << "Ingrese el apodo: ";
            getline(cin, apodo);
            Contacto c(nombre, numero, apodo, correo);
            agenda.agregar(c);
        }
        if (opc == 1)
        {
            int contact = showMenu(agenda.getLista(), "Seleccione un contacto");
            cout << agenda.llamarContacto(contact) << endl;
        }
        if (opc == 2)
        {
            cout << agenda.lista();
            cout << endl
                 << "Hay " << agenda.size() << " elementos" << endl;
        }

        pausa();

    } while (opc != 3);

    return 0;
}
