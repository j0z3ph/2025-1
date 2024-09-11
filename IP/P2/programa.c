/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segundo programa
 * @version 0.1
 * @date 2024-09-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>

#define EULER 2.7182
#define IMPRIME printf("Tu edad es: \"%i\"\nY tu altura es: %f\n", edad, altura);

int main()
{
    int edad = 0;
    float altura = 0.0f;

    const float PI = 3.1416f;

    puts("Usuario, por favor ingresa tu edad: ");
    scanf("%d", &edad);
    printf("Ahora ingrese su altura: ");
    scanf("%f", &altura);

    //PI = 4; // NO SE PUEDE

   //EULER = 3; // TAMPOCO SE PUEDE

    //printf("Tu edad es: \"%i\"\nY tu altura es: %f\n", edad, altura);
    IMPRIME
    
    return 0;
}
