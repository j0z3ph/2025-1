/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#define N 5

int main()
{
    int arrg[N];
    int suma = 0;
    float promedio = 0.0f;

    for (int i = 0; i < N; i++)
    {
        printf("Usuario, ingrese un numero entero: ");
        scanf("%i", &arrg[i]);
    }

    for (int i = 0; i < N; i++)
    {
        suma += arrg[i];
    }

    promedio = (float)suma / (float)N;

    printf("El promedio es: %.2f\n", promedio);

    return 0;
}
