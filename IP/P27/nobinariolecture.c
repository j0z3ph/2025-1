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
    int entero2;
    double doble;
    archi = fopen("archivo.bin", "rb");
    if(archi == NULL) {
        printf("Ups, no se pudo :<");
        return 1;
    }

    fread(&entero2, sizeof(int), 1, archi);
    fread(&doble, sizeof(double), 1, archi);

    printf("%i - %lf", entero2, doble);

    fclose(archi);
    
    return 0;
}
