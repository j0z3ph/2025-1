/**
 * @file ifsss.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int seleccion = 0;
    float num1 = 0.0f, num2 = 0.0f;
    printf("MENU\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%i", &seleccion);
    if (seleccion < 1 || seleccion > 5)
    {
        printf("Opcion no valida\n");
    }
    else
    {
        if (seleccion == 5)
        {
            printf("Adios");
        }
        else
        {
            printf("Ingrese el primer numero: ");
            scanf("%f", &num1);
            printf("Ingrese el segundo numero: ");
            scanf("%f", &num2);

            if (seleccion == 1)
            {
                printf("La suma es: %.2f", num1 + num2);
            }
            else if (seleccion == 2)
            {
                printf("La resta es: %.2f", num1 - num2);
            }
            else if (seleccion == 3)
            {
                printf("La multiplicacion es: %.2f", num1 * num2);
            }
            else if (seleccion == 4)
            {
                printf("La division es: %.2f", num1 / num2);
            }
        }
    }

    return 0;
}
