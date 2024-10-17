/**
 * @file matrix.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-10-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    int traspuesta[3][3];
    int adjunta[3][3];
    float inversa[3][3];
    int determinante = 0;
    float factor = 0.0f;

    determinante = (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1] * matrix[0][2]) - (matrix[2][1] * matrix[1][2] * matrix[0][0]) - (matrix[2][2] * matrix[1][0] * matrix[0][1]);
    printf("%i\n", determinante);

    if (determinante == 0)
    {
        printf("La matriz no tiene inversa :\"(\n");
    }
    else
    {
        factor = 1.0f / (float)determinante;

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                printf("%5i", matrix[fila][columna]);
            }
            printf("\n");
        }

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                traspuesta[columna][fila] = matrix[fila][columna];
            }
        }

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                printf("%5i", traspuesta[fila][columna]);
            }
            printf("\n");
        }

        // Adjunta de una matriz
        adjunta[0][0] = (traspuesta[1][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[1][2]);
        adjunta[0][1] = -1 * ((traspuesta[1][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[1][2]));
        adjunta[0][2] = (traspuesta[1][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[1][1]);
        adjunta[1][0] = -1 * ((traspuesta[0][1] * traspuesta[2][2] - traspuesta[2][1] * traspuesta[0][2]));
        adjunta[1][1] = (traspuesta[0][0] * traspuesta[2][2] - traspuesta[2][0] * traspuesta[0][2]);
        adjunta[1][2] = -1 * ((traspuesta[0][0] * traspuesta[2][1] - traspuesta[2][0] * traspuesta[0][1]));
        adjunta[2][0] = (traspuesta[0][1] * traspuesta[1][2] - traspuesta[1][1] * traspuesta[0][2]);
        adjunta[2][1] = -1 * ((traspuesta[0][0] * traspuesta[1][2] - traspuesta[1][0] * traspuesta[0][2]));
        adjunta[2][2] = (traspuesta[0][0] * traspuesta[1][1] - traspuesta[1][0] * traspuesta[0][1]);

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                printf("%5i", adjunta[fila][columna]);
            }
            printf("\n");
        }

        // Calculamos la inversa
        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                inversa[fila][columna] = factor * (float)adjunta[fila][columna];
            }
        }

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                printf("%7.2f", inversa[fila][columna]);
            }
            printf("\n");
        }
        
    }

    return 0;
}
