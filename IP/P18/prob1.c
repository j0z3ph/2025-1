/**
 * @file prob1.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-11-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include "bibfunciones.h"



int main()
{
    char cadena[100];
    printf("Usuario, favor de ingresa una cadena o te pico >:[ ");
    fgets(cadena, 100, stdin);

    dereversaPapi(cadena);
    
    return 0;
}
