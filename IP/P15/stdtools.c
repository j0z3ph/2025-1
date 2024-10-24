/**
 * @file stdtools.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Standar Tools Library
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

void imprime(int matrix[3][3])
{

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%5i", matrix[fila][columna]);
        }
        printf("\n");
    }
}

void imprimef(float matrix[3][3])
{

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            printf("%10.2f", matrix[fila][columna]);
        }
        printf("\n");
    }
}
