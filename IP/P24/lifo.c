/**
 * @file lifo.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief PILA
 * @version 0.1
 * @date 2024-11-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void agregar(int **arr, int *tamanio, int valor)
{
    if (*arr == NULL)
    {
        *arr = (int *)malloc(sizeof(int));
    }
    else
    {
        *arr = (int *)realloc(*arr, ((*tamanio) + 1) * sizeof(int));
        memcpy((*arr)+1, *arr, (*tamanio) * sizeof(int));
    }
    **arr = valor;
    (*tamanio)++;
}

int quitar(int **arr, int *tamanio)
{
    int valor;
    if (*arr == NULL)
    {
        return 0;
    }
    else
    {
        valor = **arr;
        if (*tamanio == 1)
        {
            free(*arr);
            *arr = NULL;
        }
        else
        {
            memcpy(*arr, (*arr) + 1, ((*tamanio) - 1) * sizeof(int));
            *arr = (int *)realloc(*arr, ((*tamanio) - 1) * sizeof(int));
        }
        (*tamanio)--;
    }
    return valor;
}

int main()
{
    int *arr = NULL;
    int tamanio = 0;

    agregar(&arr, &tamanio, 1);
    agregar(&arr, &tamanio, 2);
    agregar(&arr, &tamanio, 3);
    agregar(&arr, &tamanio, 4);
    agregar(&arr, &tamanio, 5);

    for (int i = 0; i < tamanio; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n%i", quitar(&arr, &tamanio));
    printf("\n%i", quitar(&arr, &tamanio));
    printf("\n%i", quitar(&arr, &tamanio));

    printf("\n");

    for (int i = 0; i < tamanio; i++)
    {
        printf("%i ", arr[i]);
    }

    return 0;
}
