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

using namespace std;
using namespace tools;

class Contacto
{
private:
    string nombre;
    string numero;
    string correo;
    string apodo;

public:
    Contacto()
    {
        this->nombre = this->apodo = this->correo = this->numero = "";
    }
    Contacto(string nombre, string numero,
             string apodo = "", string correo = "")
    {
        this->nombre = nombre;
        this->numero = numero;
        this->correo = correo;
        this->apodo = apodo;
    }

    // getters
    string getNombre() { return this->nombre; }
    string getApodo() { return this->apodo; }
    string getNumero() { return this->numero; }
    string getCorreo() { return this->correo; }

    // setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setApodo(string apodo) { this->apodo = apodo; }
    void setNumero(string numero) { this->numero = numero; }
    void setCorreo(string correo) { this->correo = correo; }
};

class Agenda
{
private:
    Contacto *_lista;
    int cont;

public:
    Agenda()
    {
        this->_lista = nullptr;
        this->cont = 0;
    }
    ~Agenda()
    {
        if (this->_lista != nullptr)
            delete[] this->_lista;
    }

    // Metodos
    int size() { return this->cont; }
    void agregar(Contacto contacto)
    {
        Contacto *tmp = new Contacto[cont + 1];
        if (cont > 0)
        {
            // Si ya hay contactos
            memcpy(tmp, this->_lista, sizeof(Contacto) * cont);
            delete[] this->_lista;
            this->_lista = tmp;
        }
        else
        {
            // Si no hay contactos
            this->_lista = tmp;
        }
        // Copiamos el contacto a la lista
        memcpy(this->_lista + cont, &contacto, sizeof(Contacto));
        cont++; // Sumamos uno
    }

    string lista()
    {
        string cadena = "";
        for (int i = 0; i < cont; i++)
        {
            cadena = cadena.append(to_string(i + 1));
            cadena = cadena.append(" - ");
            cadena = cadena.append((*(this->_lista + i)).getNombre());
            cadena = cadena.append(" - ");
            cadena = cadena.append((*(this->_lista + i)).getNumero());
            cadena = cadena.append("\n");
        }
        return cadena;
    }
};

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
            Contacto c("Nombre " + to_string(cont++), "Numero");
            agenda.agregar(c);
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
