/**
 * @file estructura.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer estructura 😍☆*: .｡. o(≧▽≦)o .｡.:*☆
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int Double;

typedef struct Fecha{
    int dia;
    int mes;
    int anio;
} Fecha;

struct Estudiante {
    char nombre[100];
    char boleta[20];
    int edad;
    Fecha fnacimiento;
};

typedef struct Estudiante Estudiante;

int main()
{
    Estudiante *es2 = (Estudiante *)malloc(sizeof(Estudiante));
    Estudiante es1;
    es1.edad = 18;
    strcpy(es1.nombre, "Joaquin");
    strcpy(es1.boleta, "202666");
    es1.fnacimiento.dia = 32;
    es1.fnacimiento.mes = 2;
    es1.fnacimiento.anio = 999;

    es2->edad = 89;
    es2->fnacimiento.dia = 10;

    (*es2).edad = 10;

    
    
    printf("%s - %s - %i - %02i/%02i/%04i\n", 
    es1.boleta, es1.nombre, es1.edad,
    es1.fnacimiento.dia, es1.fnacimiento.mes, es1.fnacimiento.anio);
    printf("\n%lu\n", sizeof(Estudiante));

    return 0;
}
