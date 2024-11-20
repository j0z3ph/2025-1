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
    int *arr[3]; // arreglo de punteros
    *arr = malloc(sizeof(int));
    *(arr + 1) = malloc(sizeof(int));
    *(arr + 2) = malloc(sizeof(int));
    *(*arr) = 10;
    *(*(arr + 1)) = 11;
    *(*(arr + 2)) = 12;
    


    printf("%p - %p - %p\n", arr, arr+1, arr+2);
    printf("%p - %p - %p\n", *arr, *(arr+1), *(arr+2));
    printf("%i - %i - %i\n", **arr, *(*(arr+1)), *(*(arr+2)));

    
    return 0;
}
