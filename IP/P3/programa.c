/**
 * @file programa.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi tercer programa
 * @version 0.1
 * @date 2024-09-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int global = 0; // VARIABLE GLOBAL (NO USAR)

int main()
{
    char nombre[10];
    float numero1 = 0.0f, numero2 = 0.0f;
    //{
    float suma = 0.0f;
    
    //}
    printf("Querido usuario, ingrese su nombre: ");
    fgets(nombre, 10, stdin);

    printf("Ahora, ingrese un numero: ");
    scanf("%f", &numero1);

    printf("Ahora, ingrese otro numero: ");
    scanf("%f", &numero2);

    suma = numero1 + numero2;

    printf("%s, la suma de %+-10.3f y %.1e es %.5f", nombre,numero1,
    numero2, suma);
    return 0;
}
