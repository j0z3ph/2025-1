/**
 * @file numeros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-10-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

void imprime2(int n, int i) {
    if (i <= n)
    {
        printf("%i ", i);
        i++;
        imprime2(n, i);
    }
}

void imprime(int n)
{
    int i = 1;
    if (i <= n)
    {
        printf("%i ", i);
        i++;
        imprime2(n, i);
    }
}

void imprime_chida(int n) {
    static int i = 1;
    if (i <= n)
    {
        printf("%i ", i);
        i++;
        imprime_chida(n);
    }
}


int main()
{
    int n = 10;

    imprime_chida(n);

    return 0;
}
