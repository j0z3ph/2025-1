/**
 * @file punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mas punteros 🥰
 * @version 0.1
 * @date 2024-11-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int (*arr)[3]; // puntero a arreglos
    arr = malloc(sizeof(int)*9);
    *(*arr) = 10;
    *((*arr) + 1) = 11;
    *((*arr) + 2) = 12;
    int cont = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = cont++;
        }
    }
    


    printf("%p - %p\n", arr, arr+1);
    printf("%p - %p - %p\n", *arr, *arr+1, *arr +2);
    printf("%i - %i - %i\n", **arr, *(*arr+1), *(*arr +2));
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%i ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
