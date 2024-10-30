/**
 * @file fors.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer for
 * @version 0.1
 * @date 2024-10-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>

int main()
{
    int siete = 7;
    int contador = 1;
    for (;contador <= 10;)
    {
        printf("%i x %i = %i\n", siete,
               contador, siete * contador);
        contador++;
    }

    return 0;
}
