/**
 * @file funciones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer biblioteca de funcioooooones :>
 * @version 0.1
 * @date 2024-10-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include<stdio.h>

int suma(int a, int b) {
    int c;
    a = 10;
    c = a + b;
    return c;
}

int suma_ref(int *a, int *b) {
    int c;
    *a = 10;
    c = *a + *b;
    return c;
}