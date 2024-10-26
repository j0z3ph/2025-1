/**
 * @file facto.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Factorial recursivo
 * @version 0.1
 * @date 2024-10-25
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int factorial(int n);

int main()
{
    printf("%i\n", factorial(40));
    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
    {
        return n * factorial(n - 1);
    }
}
