/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-10-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 101

int main()
{
    int arr[N];
    int aux, cont = 0, ini = 0, fin = N - 1, mit = 0;
    int perdido = 8;
    int encontrado = 0;
    
    srand(time(NULL));
    // Genera numeros aleatorios y los guarda
    // en un arreglo
    for (int i = 0; i < N; i++)
    {
        arr[i] = (rand() % (2 * N)) - N;
    }

    // Imprime un arreglo
    printf("[ ");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("]\n");

    // Aqui comienza el burbujazo
    for (int j = 0; j < N - 1; j++)
    {
        for (int i = 0; i < N - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                cont++;
                aux = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = aux;
            }
        }
        if (cont == 0)
        {
            break;
        }
        cont = 0;
    }

    // Imprime un arreglo
    printf("[ ");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("]\n");

    // Busqueda Binaria
    while (fin >= ini)
    {
        mit = (ini + fin) / 2;
        if(arr[mit] == perdido){
            encontrado = 1;
            break;
        } else if (arr[mit] > perdido) {
            fin = mit - 1;
        } else {
            ini = mit + 1;
        }
    }

    if (!encontrado) {
        printf("Upps, no ta :'C\n");
    } else {
        printf("Si ta :'D\n");
    }
    


    return 0;
}
