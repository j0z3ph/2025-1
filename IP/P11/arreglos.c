/**
 * @file arreglos.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 5

int main()
{
    int arr[5];
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        printf("%i\n", (rand()%11)+10);
    }
    
    


    return 0;
}
