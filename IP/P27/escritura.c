/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Archivos
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    FILE *archi;
    int entero = 10;
    archi = fopen("archivo.txt", "a");
    if(archi == NULL) {
        printf("No se pudo :C");
        return 1;
    }

    fprintf(archi, "%i", entero);
    fclose(archi);
    
    return 0;
}
