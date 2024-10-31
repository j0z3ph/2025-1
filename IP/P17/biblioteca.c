/**
 * @file biblioteca.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi biblioteca
 * @version 0.1
 * @date 2024-10-29
 * 
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void imprimehastan(int n)
{
    static int i = 1;
    if (i <= n)
    {
        printf("%i ", i);
        i++;
        imprimehastan(n);
    }
}

void _generar(int n, int arrg[])
{
    static int i = 0;
    if (i < n)
    {
        arrg[i] = rand() % 1001;
        i++;
        _generar(n, arrg);
    }
}

void generar(int n, int arrg[])
{
    srand(time(NULL));
    _generar(n, arrg);
}

void _imprime(int arrg[], int n)
{
    static int i = 0;
    if (i < n)
    {
        printf("%i ", arrg[i]);
        i++;
        _imprime(arrg, n);
    }
}


void imprime(int arrg[], int n)
{
    printf("[ ");
    _imprime(arrg, n);
    printf("]");
}


void _encuentraElMasGrande(int arr[], int n, int *theBigOne)
{
    static int i = 0;
    if (i < 10)
    {
        *theBigOne = arr[i] > *theBigOne ? arr[i] : *theBigOne;
        i++;
        _encuentraElMasGrande(arr, n, theBigOne);
    }
}

void encuentraElMasGrande(int arr[], int n)
{
    int theBigOne = -__INT_MAX__;
    _encuentraElMasGrande(arr, n, &theBigOne);
    printf("\nEl mas grande es: %i\n", theBigOne);
}

int cuentaDigitos(int numero)
{
    static int contador = 0;
    if (numero)
    {
        numero /= 10;
        contador++;
        cuentaDigitos(numero);
    }
    return contador;
}