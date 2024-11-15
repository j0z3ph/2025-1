/**
 * @file memoriachida.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mas memoria dinamica :>
 * @version 0.1
 * @date 2024-11-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

void nada() {
    int *a = new int[2000];
    delete[] a;
}

class Alumno {
    private:
    string nombre;
    int edad;
    int boleta;

    public:
    Alumno(string nombre, int edad, int boleta) :
    nombre(nombre), edad(edad), boleta(boleta) {}

    // getters 
    string getNombre() { return this->nombre; }
    int getEdad() { return this->edad; }
    int getBoleta() { return this->boleta; }

    // setters
    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setBoleta(int boleta) { this->boleta = boleta; }

    // metodos 
    string saluda() {
        string saludo = "Holi, mi nombre es ";
        saludo = saludo.append(this->nombre);
        saludo = saludo.append(", y tengo ");
        saludo = saludo.append(to_string(this->edad));
        saludo = saludo.append(" años.");
        return saludo;
    }

};


int main()
{
    Alumno *al = new Alumno("Ian", 19, 12345);
    Alumno al2("Lluvia", 18, 76523);

    cout << al->saluda();
    cout << al2.saluda();
    
    delete al;
    
    return 0;
}
