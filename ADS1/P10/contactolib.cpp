
#include <iostream>
#include <vector>
#include <algorithm>
#include "contactolib.hpp"

using namespace std;
using namespace agenda;

Contacto::Contacto()
{
    this->nombre = "";
    this->numero = "";
    this->correo = "";
    this->apodo = "";
}

Contacto::Contacto(string nombre, string numero,
                   string apodo, string correo)
{
    this->nombre = nombre;
    this->numero = numero;
    this->correo = correo;
    this->apodo = apodo;
}

// getters
string Contacto::getNombre() { return this->nombre; }
string Contacto::getApodo() { return this->apodo; }
string Contacto::getNumero() { return this->numero; }
string Contacto::getCorreo() { return this->correo; }

// setters
void Contacto::setNombre(string nombre) { this->nombre = nombre; }
void Contacto::setApodo(string apodo) { this->apodo = apodo; }
void Contacto::setNumero(string numero) { this->numero = numero; }
void Contacto::setCorreo(string correo) { this->correo = correo; }

Agenda::Agenda()
{
    this->_lista = nullptr;
    this->cont = 0;
}
Agenda::~Agenda()
{
    if (this->_lista != nullptr)
        delete[] this->_lista;
}

// Metodos
int Agenda::size() { return this->cont; }
void Agenda::agregar(Contacto contacto)
{
    //void *mem = operator new[]((sizeof(Contacto) * cont) + sizeof(Contacto));
     Contacto *tmp = new Contacto[cont + 1];
    //Contacto *tmp = static_cast<Contacto *>(mem);
    // Contacto *tmp = (Contacto *)mem;
    if (cont > 0)
    {
        // Si ya hay contactos
        // memcpy(tmp, this->_lista, sizeof(Contacto) * cont);
        copy(_lista, _lista + cont, tmp);
        //operator delete[](this->_lista);
        delete[](this->_lista);
        this->_lista = tmp;
    }
    else
    {
        // Si no hay contactos
        this->_lista = tmp;
    }
    // Copiamos el contacto a la lista
    copy(&contacto, (&contacto) + 1, _lista + cont);
    // memcpy(this->_lista + cont, &contacto, sizeof(Contacto));
    cont++; // Sumamos uno
}

vector<string> Agenda::getLista()
{
    string elemento;
    vector<string> lalista;
    for (int i = 0; i < cont; i++)
    {
        elemento = _lista[i].getNombre() + " - " + _lista[i].getApodo();
        lalista.push_back(elemento);
    }
    return lalista;
}

string Agenda::llamarContacto(int id)
{
    string msj = "Llamando a " + _lista[id].getNombre() + "(" + _lista[id].getNumero() + ")...";
    return msj;
}

string Agenda::lista()
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