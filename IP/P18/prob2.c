/**
 * @file prob2.c
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
    char cadena[] = "  Jelow       Mundeychion :)  ";
    int cont = 0;

    for (int i = 0; i < tamanioCadena(cadena); i++)
    {
        if(cadena[i] == 32) {
            cont++;
        }
    }
    cont++;

    printf("La cadena tiene %i palabras.\n", cont);
    
    
    return 0;
}
