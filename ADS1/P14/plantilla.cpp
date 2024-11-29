/**
 * @file plantilla.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Plantillas
 * @version 0.1
 * @date 2024-11-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

using namespace std;

template <typename T>
T suma(T a, T b)
{
    return a + b;
}

template <class T>
class Lista
{
private:
    T *_lista;
    int _cont;

public:
    Lista()
    {
        _lista = nullptr;
        _cont = 0;
    }
    void agregar(T valor)
    {
        if (_cont == 0)
        {
            _lista = new T[1];
            *_lista = valor;
        }
        else
        {
            T *tmp = new T[_cont + 1];
            copy(_lista, _lista + _cont, tmp);
            *(tmp + _cont) = valor;
            delete[] _lista;
            _lista = tmp;
        }
        _cont++;
    }

    int size()
    {
        return _cont;
    }
};

int main()
{
    Lista<double> lista;

    return 0;
}
