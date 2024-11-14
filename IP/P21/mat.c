/**
 * @file mat.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segunda matrix :*
 * @version 0.1
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

int main()
{
    int matriz[3][3];

    for (int i = 0; i < 9; i++)
        *(*matriz + i) = i;

    for (int i = 0; i < 9; i++)
        printf("%i%c", (*matriz)[i], (((i + 1) % 3) ? ' ' : '\n'));

    return 0;
}
