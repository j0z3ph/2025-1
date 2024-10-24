/**
 * @file stdla.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Linear Algebra Standar Library 
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __STDLA_H__
#define __STDLA_H__

#define TRUE 1
#define FALSE 0

/// @brief Calcula el determinante de una matriz de 3x3
/// @param matrix La matriz a calcular su determinante
/// @return El determinante
int determinante(int matrix[3][3]);

/// @brief Calcula la traspuesta de una matriz de 3x3
/// @param matrix La matriz
/// @param tras La matriz traspuesta
void traspuesta(int matrix[3][3], int tras[3][3]);

/// @brief Calcula la adjunta de una matriz de 3x3
/// @param matrix La matriz
/// @param adj La matriz adjunta
void adjunta(int matrix[3][3], int adj[3][3]);

/// @brief Calcula la inversa de una matriz
/// @param matrix La matriz
/// @param inv La inversa
/// @return TRUE si tiene inversa. FALSE en cualquier otro caso.
int inversa(int matrix[3][3], float inv[3][3]);

/// @brief Imprime una matriz de enteros
/// @param matrix La matriz a imprimir
void imprime(int matrix[3][3]);

/// @brief Imprime una matriz de flotantes
/// @param matrix La matriz a imprimir
void imprimef(float matrix[3][3]);

#endif