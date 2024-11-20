#ifndef __CONTACTOLIB_HPP__
#define __CONTACTOLIB_HPP__

#include <iostream>
#include <vector>

using namespace std;

namespace agenda
{

    class Contacto
    {
    private:
        string nombre;
        string numero;
        string correo;
        string apodo;

    public:
        Contacto(string nombre, string numero,
                 string apodo = "", string correo = "");

        // getters
        string getNombre();
        string getApodo();
        string getNumero();
        string getCorreo();

        // setters
        void setNombre(string nombre);
        void setApodo(string apodo);
        void setNumero(string numero);
        void setCorreo(string correo);
    };

    class Agenda
    {
    private:
        Contacto *_lista;
        int cont;

    public:
        Agenda();
        ~Agenda();

        // Metodos
        int size();
        void agregar(Contacto contacto);
        vector<string> getLista();

        string llamarContacto(int id);

        string lista();
    };

} // namespace name

#endif