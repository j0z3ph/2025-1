/**
 * @file masgrande.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Encuentra el mas grande en un arreglo
 * @version 0.1
 * @date 2024-10-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include "biblioteca.h"


int main()
{
    int arr[10];

    generar(10, arr);
    imprime(arr, 10);
    encuentraElMasGrande(arr, 10);

    return 0;
}
