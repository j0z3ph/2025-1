/**
 * @file nobinario.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
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
    double doble = 3.1416;
    archi = fopen("archivo.bin", "wb");
    if(archi == NULL) {
        printf("Ups, no se pudo :<");
        return 1;
    }

    fwrite(&entero, sizeof(int), 1, archi);
    fwrite(&doble, sizeof(double), 1, archi);



    fclose(archi);
    
    return 0;
}
