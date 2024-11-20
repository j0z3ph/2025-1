/**
 * @file promedio.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Programa que pide numeros y devuelve el
 * promedio 😘
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
    char *entrada = (char *)malloc(sizeof(char) * 100);
    double suma = 0.0, prom;
    double *numeros = NULL;
    int cont = 0;

    do
    {
        printf("Ingrese un numero o c para terminar: ");
        fgets(entrada, 100, stdin);

        if (numeros == NULL)
            numeros = (double *)malloc(sizeof(double));
        else
            numeros = (double *)realloc(numeros, (cont + 1) * sizeof(double));

        *(numeros + cont) = atof(entrada);
        cont++;
    } while (entrada[0] != 'c');

    for (int i = 0; i < cont - 1; i++)
    {
        suma += *(numeros + i);
    }

    prom = suma / (double)(cont - 1);

    printf("El promedio es: %lf 😎\n", prom);

    return 0;
}
