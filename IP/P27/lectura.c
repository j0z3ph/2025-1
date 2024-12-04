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
#include <stdio.h>

int main()
{
    FILE *archi;
    char cadena[100], caracter;
    int entero = 10;
    archi = fopen("archivo.txt", "r");
    if (archi == NULL)
    {
        printf("No se pudo :C");
        return 1;
    }

    fscanf(archi, "%i", &entero);
    printf("%i", entero);

    // while (!feof(archi))
    // {   
    //     caracter = getc(archi);

    //     //fgets(cadena, 100, archi);

    //     //printf("%s", cadena);
    //     putc(caracter, stdout);
    // }

    fclose(archi);

    return 0;
}
