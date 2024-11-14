/**
 * @file arr.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi segunda vez con arreglos :>
 * @version 0.1
 * @date 2024-11-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>

int main()
{
    int arrg[10];
    int *ptr;
    ptr = arrg;

    printf("%p\n", ptr);
    printf("%p\n", &ptr);

    for (int i = 0; i < 10; i++)
    {
        //*(arrg+i) = i;
        //arrg[i] = i;
        ptr[i] = i;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%p - %i\n", ptr+i, *(ptr+i));
    }
    
    
    
    return 0;
}
