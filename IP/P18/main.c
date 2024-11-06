/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Manejo de cadenas
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    char cadena[] = "Holi canoli";
    puts(cadena);

    cadena[5] = '\0';
    puts(cadena);

    return 0;
}
