/**
 * @file ifss.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Trata de IFSSS
 * @version 0.1
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int edad = 0;
    printf("Usuario, ingrese su edad: ");
    scanf("%i", &edad);

    if (edad < 0)
    {
        printf("Ora pues, no estes jugando. Edad no valida\n");
    }
    else if (edad >= 0 && edad < 18)
    {
        printf("Buena noche niño\n");
    }
    else if (edad >= 18 && edad <= 150)
    {
        printf("Buena noche joven adulto\n");
    }
    else
    {
        printf("Ora pues, no estes jugando. Edad no valida\n");
    }

    return 0;
}
