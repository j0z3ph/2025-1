/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de BREAK y CONTINUE
 * @version 0.1
 * @date 2024-09-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    int cont = 0;
    while(cont < 100) {
        cont++;
        if(cont%2 != 0) break;
        

        printf("%i\n", cont);
        
    }
    
    return 0;
}
