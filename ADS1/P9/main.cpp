/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

class Persona
{
private:
    string nombre;
    string ap1;
    string ap2;
    int edad;

public:
    Persona(string nombre, string ap1, string ap2, int edad) : 
    nombre(nombre), ap1(ap1), ap2(ap2), edad(edad) {}

    // setters
    void setNombre(string n) { this->nombre = n; }
    void setApellidoPaterno(string ap) { this->ap1 = ap; }
    void setApellidoMaterno(string ap) { this->ap2 = ap; }
    void setEdad(int e) { this->edad = e; }

    // getters
    string getNombre() { return this->nombre; }
    string getApellidoPaterno() {return this->ap1; }
    string getApellidoMaterno() { return this->ap2; }
    int getEdad() { return this->edad; }

    string saluda() {
        string cadena = "Hola, mi nombre es ";
        cadena = cadena.append(this->nombre);
        return cadena;
    }
};

int main()
{
    Persona *p1 = new Persona("Jose Luis", "Cruz", "Mora", 18);
    cout << p1->saluda() << endl;

    cout << (*p1).saluda() << endl;

    delete p1;
    return 0;
}
