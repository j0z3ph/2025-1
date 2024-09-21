/**
 * @file enenumeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Este programa pide ENE numeros al usuario y devuelve
 * el promedio.
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma = 0;
    int cont = 0;
    float promedio = 0.0f;
    char entrada[100];

    do
    {
        printf("Usuario, ingrese un numero o 'c' para terminar: ");
        fgets(entrada, 100, stdin);
        suma += atoi(entrada);
        cont++;
    } while (entrada[0] != 'c');

    promedio = cont == 1 ? 0 : (float)suma / (float)(--cont);

    printf("El promedio es: %f\n", promedio);

    return 0;
}
