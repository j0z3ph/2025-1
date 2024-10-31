
/**
 * @file biblioteca.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi biblioteca
 * @version 0.1
 * @date 2024-10-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __BIBLIOTECA_H__
#define __BIBLIOTECA_H__

/**
 * @brief Imprime hasta N usando recursion
 * 
 * @param n Pues N
 */
void imprimehastan(int n);

/**
 * @brief Genera un arreglo de numeros aleatorios
 * 
 * @param n La cantidad de numeros a generar 
 * @param arrg El arreglo donde se generaran
 */
void generar(int n, int arrg[]);

/**
 * @brief Imprime un arreglo
 * 
 * @param arrg El arreglo a imprimir
 * @param n El tamaño del arreglo
 */
void imprime(int arrg[], int n);

/**
 * @brief Encuentra en numero mas grande en un arreglo 
 * desordenado
 * 
 * @param arr El arreglo
 * @param n El tamaño del arreglo
 */
void encuentraElMasGrande(int arr[], int n);

/**
 * @brief Cuenta el numero de digitos que 
 * tiene un entero
 * 
 * @param numero El entero a evaluar
 * @return int El numero de digitos del entero
 */
int cuentaDigitos(int numero);

#endif