/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi cuarto programa
 * @version 0.1
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    int entero = 0;
    printf("Querido usuario, ingrese un numero entero: ");
    scanf("%i", &entero);

    //printf("El numero %i es %s\n", entero, (entero % 2 == 0 ? "PAR": "IMPAR"));
    //printf("El numero %i es %s\n", entero, (((entero & 1) == 0) && ((entero & 1) != 1) ? "PAR": "IMPAR"));
    printf("El numero %i es %s\n", entero, (!(((entero & 1) == 0) && ((entero & 1) != 1)) ? "IMPAR": "PAR"));
    return 0;
}
