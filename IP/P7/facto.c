/**
 * @file facto.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int numero = 0;
    int facto = 1;

    printf("Usuario, ingresa un numero: ");
    scanf("%d", &numero);

    for (int i = numero; i > 0; i--)
    {
        printf("%i %c ", i, i == 1 ? '=' : 'x');
        facto *= i;
    }

    printf("%i\n", facto);
    return 0;
}
