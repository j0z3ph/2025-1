/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de sobreescritura
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>

using namespace std;

class Prueba {
    protected:
    int valor;

    public:
    void setValor(int valor) { this->valor = valor; }
    int getValor() { return this->valor; }

    string tostring() {
        return "";
    }
};

class Hija : public Prueba
{
    public:
    // sobreescritura de funciones
    string tostring() {
        return to_string(valor);
    }
    // sobrecarga de funciones
    string tostring(int valor) {
        return to_string(valor);
    }

};

int main()
{
    Hija h;
    h.setValor(10);
    cout << h.tostring() << endl << h.tostring(100) << endl << h.Prueba::tostring();
    return 0;
}
