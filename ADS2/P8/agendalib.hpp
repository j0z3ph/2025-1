#ifndef __AGENDALIB_HPP__
#define __AGENDALIB_HPP__

#include <iostream>
#include <vector>

using namespace std;
namespace agenda
{

    class Contacto
    {
    private:
        string nombre;
        string telefono;
        string apodo;

    public:
        Contacto();
        Contacto(string nombre, string telefono, string apodo = "");

        // getters
        string getNombre();
        string getTelefono();
        string getApodo();

        // setters
        void setNombre(string nombre);
        void setTelefono(string telefono);
        void setApodo(string apodo);
    };

    class Agenda
    {
    private:
        Contacto *_lista;
        int _cont;

    public:
        Agenda();
        ~Agenda();

        void agregar(Contacto contacto);
        int tamanio();
        vector<string> listaContactos();
        string llamarContacto(int id);
        string listar();
    };
}

#endif