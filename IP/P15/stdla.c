/**
 * @file stdla.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Linear Algebra Standar Library
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "stdla.h"

int determinante(int matrix[3][3])
{
    return (matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) + (matrix[0][2] * matrix[1][0] * matrix[2][1]) - (matrix[2][0] * matrix[1][1] * matrix[0][2]) - (matrix[2][1] * matrix[1][2] * matrix[0][0]) - (matrix[2][2] * matrix[1][0] * matrix[0][1]);
}

void traspuesta(int matrix[3][3], int tras[3][3])
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            tras[columna][fila] = matrix[fila][columna];
        }
    }
}

void adjunta(int matrix[3][3], int adj[3][3])
{
    // Adjunta de una matriz
    adj[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    adj[0][1] = -1 * ((matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]));
    adj[0][2] = (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);
    adj[1][0] = -1 * ((matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]));
    adj[1][1] = (matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2]);
    adj[1][2] = -1 * ((matrix[0][0] * matrix[2][1] - matrix[2][0] * matrix[0][1]));
    adj[2][0] = (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
    adj[2][1] = -1 * ((matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]));
    adj[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
}

int inversa(int matrix[3][3], float inv[3][3])
{
    int det = determinante(matrix);
    float factor = 1.0f / (float)det;
    int tras[3][3];
    int adj[3][3];
    if (det == 0)
        return FALSE;

    traspuesta(matrix, tras);
    adjunta(tras, adj);

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            inv[fila][columna] = factor * (float)adj[fila][columna];
        }
    }

    return TRUE;
}

