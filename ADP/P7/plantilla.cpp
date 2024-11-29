/**
 * @file plantilla.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>

using namespace std;

template<typename T>
T suma(T a, T b) {
    return a + b;
}

template<class T>
class Lista {
    private:
    T *_lista;
    int _cont;

    public:
    Lista() {
        _lista = nullptr;
        _cont = 0;
    }

    void agregar(T v) {
        if(_cont == 0) {
            _lista = new T[1];
            *_lista = v;
            _cont++;
        } else {
            T *tmp = new T[_cont + 1];
            copy(_lista, _lista + _cont, tmp);
            *(tmp + _cont) = v;
            _cont++;
            delete[] _lista;
            _lista = tmp;
        }
    }

    T valor(int idx) {
        return _lista[idx];
    }

    int size() {
        return _cont;
    }
};

int main()
{
    Lista<int> l;
    l.agregar(1);
    l.agregar(100);

    for (size_t i = 0; i < l.size(); i++)
    {
        cout << l.valor(i) << " ";
    }
    
    
    return 0;
}
