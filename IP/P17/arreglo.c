/**
 * @file arreglo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Imprime el contenido de un arreglo usando recursion
 * @version 0.1
 * @date 2024-10-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include "biblioteca.h"
#define N 5


int main()
{
    int arrg[N];
    generar(N, arrg);
    imprime(arrg, N);
    return 0;
}
