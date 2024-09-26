/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int arreglo[8];

    for (int i = 0; i < 10; i++)
    {
        arreglo[i] = i;
    }

    printf("[ ");
    for (int i = 0; i <= 10; i++)
    {
        printf("%i ", arreglo[i]);
    }
    printf("]\n");

    arreglo[-100] = 666;
    printf("%i\n", arreglo[-100]);

    return 0;
}
