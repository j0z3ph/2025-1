/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief El main
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    if(argc == 1) {
        printf("Asi no se usa este programa, tonoto >:O\n");
        return 24;
    }
    if (argc > 1)
    {
        if (argv[1][0] == 'h')
        {
            printf("Este programa resta dos numeros\n");
            printf("Uso: suma.exe numero1 numero2\n");
            printf("Retorna la resta\n");
            return 0;
        }
    }

    if(argc >= 3) {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
        return num1 - num2;
    }

    return 0;
}
