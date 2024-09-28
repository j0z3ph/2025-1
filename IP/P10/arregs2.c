/**
 * @file arregs2.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-09-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    char arrg[3] = {'a', 'b', 'c'};
    int arrg2[3];

    printf("%p - %p\n", &arrg2[0], arrg2+1);
    
    return 0;
}
