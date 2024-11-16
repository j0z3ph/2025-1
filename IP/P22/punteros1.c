/**
 * @file punteros1.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer memoria dinamica :>
 * @version 0.1
 * @date 2024-11-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

void nada()
{
    int *a = (int *)malloc(sizeof(int) * 2000);
    free(a);
}

int main()
{
    while(100) {
        nada();
    }
    
    /*

    // MALLOC
    int *entero = NULL;
    entero = (int *)malloc(4);

    *entero = 19;

    printf("%p\n%i\n", entero, *entero);

    // CALLOC
    int *entero2 = (int *)calloc(1, sizeof(int));
    *entero2 = 666;
    printf("%p\n%i\n", entero2, *entero2);

    // REALLOC
    entero2 = (int *)realloc(entero2, 20000 * sizeof(int));
    printf("%p\n%i\n", entero2, *entero2);

    entero2 = (int *)realloc(entero2, 200 * sizeof(int));
    printf("%p\n%i\n", entero2, *entero2);

    */
    return 0;
}
