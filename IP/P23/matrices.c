/**
 * @file matrices.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mas matrices 🤪
 * @version 0.1
 * @date 2024-11-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int filas, columnas;
    printf("Ingrese las dimensiones en formato filasxcolumnas: ");
    scanf("%ix%i", &filas, &columnas);

    int(*matriz)[columnas];
    matriz = calloc(filas * columnas, sizeof(int));

    for (int i = 0; i < filas * columnas; i++)
    {
        *(*matriz + i) = i + 1;
    }

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            printf("%5i ", matriz[f][c]);
        }
        printf("\n");
    }

    return 0;
}
