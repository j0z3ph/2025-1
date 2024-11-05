/**
 * @file bibfunciones.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer biblioteca de funciones :>
 * @version 0.1
 * @date 2024-11-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
// Definiciones de funciones

namespace telematica
{

    int suma(int a, int b)
    {
        int resultado = a + b;
        return resultado;
    }

    void imprime(int entero)
    {
        std::cout << entero;
    }

} // namespace telematica
