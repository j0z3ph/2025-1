/**
 * @file para.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-09-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    // Valor inicial
    for (int cont = 1; cont <= 10; cont++) // Valor final
    {
        printf("7x%i=%i\n", cont, 7 * cont);
        // Incremento/decremento o lo quesea que haga que eventualmente la condicion se haga falsa
    }

    /*for (;;)
    {
        printf("Hola\n");
    }*/

    return 0;
}