#include <iostream>
#include <vector>
#include "agendalib.hpp"

using namespace std;
using namespace agenda;

Contacto::Contacto()
{
    this->nombre = this->telefono = this->apodo = "";
}
Contacto::Contacto(string nombre, string telefono, string apodo)
{
    this->nombre = nombre;
    this->telefono = telefono;
    this->apodo = apodo;
}

// getters
string Contacto::getNombre() { return this->nombre; }
string Contacto::getTelefono() { return this->telefono; }
string Contacto::getApodo() { return this->apodo; }

// setters
void Contacto::setNombre(string nombre) { this->nombre = nombre; }
void Contacto::setTelefono(string telefono) { this->telefono = telefono; }
void Contacto::setApodo(string apodo) { this->apodo = apodo; }

Agenda::Agenda()
{
    _lista = nullptr;
    _cont = 0;
}
Agenda::~Agenda()
{
    if (_lista != nullptr)
    {
        delete[] _lista;
    }
}

void Agenda::agregar(Contacto contacto)
{
    if (_cont == 0)
    {
        _lista = new Contacto[1];
        memcpy(_lista, &contacto, sizeof(Contacto));
    }
    else
    {
        Contacto *tmp = new Contacto[_cont + 1];
        memcpy(tmp, _lista, sizeof(Contacto) * _cont);
        memcpy(tmp + _cont, &contacto, sizeof(Contacto));
        delete[] _lista;
        _lista = tmp;
    }
    _cont++;
}

int Agenda::tamanio()
{
    return _cont;
}

vector<string> Agenda::listaContactos()
{
    string contacto = "";
    vector<string> lista;
    for (int i = 0; i < _cont; i++)
    {
        contacto = _lista[i].getNombre() + " - " + _lista[i].getApodo();
        lista.push_back(contacto);
    }
    return lista;
}

string Agenda::llamarContacto(int id)
{
    string msj = "Llamando a " + _lista[id].getNombre() + " (" + _lista[id].getTelefono() + ")...";
    return msj;
}

string Agenda::listar()
{
    string laLista = "";
    for (int i = 0; i < _cont; i++)
    {
        laLista.append(to_string(i + 1) + ". ");
        laLista.append(_lista[i].getNombre());
        laLista.append("(");
        laLista.append(_lista[i].getApodo());
        laLista.append(")");
        laLista.append(" - ");
        laLista.append(_lista[i].getTelefono());
        laLista.append("\n");
    }
    return laLista;
}
