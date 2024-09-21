/**
 * @file cinconumeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Este programa pide al usuario 5 numeros y devuelve su promedio.
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int suma = 0;
    int temp = 0;
    float promedio = 0.0f;

    for (int i = 1; i <= 5; i++)
    {
        printf("Usuario, ingrese un numero: ");
        scanf("%i", &temp);
        suma += temp;
    }

    promedio = (float)suma / 5.0f;

    printf("El promedio es %f\n", promedio);

    return 0;
}
