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
#include "stdla.h"
#include "stdtools.h"

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 10}};
    float inv[3][3];

    imprime(matrix);
    if (inversa(matrix, inv))
    {
        imprimef(inv);
    }
    else
    {
        printf("La matriz no tiene inversa :'C\n");
    }

    return 0;
}
