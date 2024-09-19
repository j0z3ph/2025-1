/**
 * @file domientras.c
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
    int cont = 11;// Valor inicial
    do
    {
        printf("7x%i=%i\n", cont, 7 * cont);
        cont++; // Incremento/decremento o lo quesea que haga que eventualmente la condicion se haga falsa
    } while (cont <= 10); // Valor final

    return 0;
}
