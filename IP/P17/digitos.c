/**
 * @file digitos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-10-30
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include "biblioteca.h"

int main()
{
    int numero = 0;
    int contador = 0;
    printf("Usuario, ingrese un numero entero positivo: ");
    scanf("%i", &numero);

    contador = cuentaDigitos(numero);

    printf("El numero ingresado tiene %i digitos.\n", contador);

    return 0;
}
