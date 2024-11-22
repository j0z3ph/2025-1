/**
 * @file agenda.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-11-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include <vector>
#include "tools.hpp"

using namespace std;
using namespace tools;

class Contacto
{
private:
    string nombre;
    string numero;
    string correo;

public:
    // getters
    string getNombre() { return this->nombre; }
    string getNumero() { return this->numero; }
    string getCorreo() { return this->correo; }

    // setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setNumero(string numero) { this->numero = numero; }
    void setCorreo(string correo) { this->correo = correo; }
};

class Agenda
{
private:
    Contacto *lista;
    int contador;

public:
    Agenda()
    {
        this->lista = nullptr;
        this->contador = 0;
    }
    ~Agenda()
    {
        if (this->lista != nullptr)
        {
            delete[] this->lista;
        }
    }

    int tamanio() { return this->contador; }

    void agregar(Contacto contacto)
    {
        if (contador == 0)
        {
            this->lista = new Contacto[contador + 1];
            memcpy(this->lista, &contacto, sizeof(Contacto));
            this->contador++;
        }
        else
        {
            Contacto *tmp = new Contacto[contador + 1];
            memcpy(tmp, this->lista, sizeof(Contacto) * this->contador);
            memcpy(tmp + 1, &contacto, sizeof(Contacto));
            delete[] this->lista;
            this->lista = tmp;
            this->contador++;
        }
    }

    string llamar(int id)
    {
        return "Llamando a " + this->lista[id].getNombre() +
               " (" + this->lista[id].getNumero() + ")...";
    }

    vector<string> listar()
    {
        string cadena = "";
        vector<string> v;

        for (int i = 0; i < this->contador; i++)
        {
            cadena =
                this->lista[i].getNombre() + " - " +
                this->lista[i].getNumero() + " - " +
                this->lista[i].getCorreo();
            v.push_back(cadena);
        }
        return v;
    }
};

int main()
{
    vector<string> menu;
    int opcion = 0, conID;
    Agenda agenda;
    string nombre, numero, correo;
    menu.push_back("Agregar");
    menu.push_back("Llamar");
    menu.push_back("Listar");
    menu.push_back("Salir");

    do
    {
        opcion = showMenu(menu, "Agenda de contactos");

        if (opcion == 0)
        {
            // Agregar
            cout << "Ingrese un nombre: ";
            getline(cin, nombre);
            cout << "Ingrese un telefono: ";
            getline(cin, numero);
            cout << "Ingrese un correo: ";
            getline(cin, correo);
            Contacto c;
            c.setNombre(nombre);
            c.setNumero(numero);
            c.setCorreo(correo);
            agenda.agregar(c);
        }
        if (opcion == 1)
        {
            conID = showMenu(agenda.listar(), "Seleccione un contacto");
            cout << agenda.llamar(conID);
        }
        if (opcion == 2)
        {
            // Listar
            vector<string> v = agenda.listar();
            for (int i = 0; i < v.size(); i++)
            {
                cout << to_string(i+1) << ". " << v[i] << endl;
            }
        }
        pausa();

    } while (opcion != 3);

    return 0;
}
