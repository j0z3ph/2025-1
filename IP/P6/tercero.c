/**
 * @file tercero.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int numero = 0;
    int suma = 0;
    printf("Querido y muy amado usuario, ingrese un numero entero: ");
    scanf("%i", &numero);

    while (numero != 0)
    {
        suma += (numero % 10);
        numero /= 10;
    }

    printf("La suma es: %i\n", suma);

    return 0;
}
