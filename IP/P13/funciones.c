/**
 * @file funciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

// Aqui arriba van las declaraciones

/// @brief Esta funcion suma dos numeros enteros.
/// @param a El primer numero
/// @param b El segundo numero
/// @return La suma de a y b
int suma(int a, int b);

/// @brief Esta funcion resta dos numeros enteros.
/// @param a El primer numero
/// @param b El segundo numero
/// @return La resta de a y b
int resta(int a, int b);

void imprime(int numero);


int main()
{
    
    imprime(resta(5,6));
    
    return 0;
}

// Aqui abajo van las definiciones
int suma(int a, int b) {
    int c;
    c = a + b;
    return c;
}

int resta(int a, int b) {
    return a - b;
}

void imprime(int numero) {
    printf("%i\n", numero);
}