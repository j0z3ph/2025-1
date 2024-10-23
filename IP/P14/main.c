/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-10-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include "funciones.h"


int main()
{
    int a= 5, b = 10;
    printf("%i\n", suma_ref(&a , &b));
    printf("%i\n", a);
    
    return 0;
}

