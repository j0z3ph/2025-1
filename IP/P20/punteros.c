/**
 * @file punteros.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer puntero :>
 * @version 0.1
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    int variable = 10;
    int *ptr;
    ptr = &variable;
    *ptr = 666;

    printf("%i\n", variable);
    printf("%p\n", &variable);
    printf("%p\n", ptr);
    printf("%i\n", *ptr);
    printf("%p\n", &ptr);
    printf("%i\n", *(&ptr+1));
    
    return 0;
}
