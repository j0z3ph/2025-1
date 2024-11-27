/**
 * @file agenda.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Agenda de contactos
 * @version 0.1
 * @date 2024-11-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

typedef struct Contacto
{
    char nombre[100];
    char numero[20];
    char apodo[50];
    char correo[50];
} Contacto;

void agregar(Contacto **lista, int *contador, Contacto contacto)
{
    if (*lista == NULL)
    {
        // La lista esta vacia
        *lista = (Contacto *)malloc(sizeof(Contacto));
        memcpy(*lista, &contacto, sizeof(Contacto));
        (*contador)++;
    }
    else
    {
        // Ya tenemos al menos un elemento
        *lista = realloc(*lista, sizeof(Contacto) * (*contador + 1));
        memcpy(*lista + *contador, &contacto, sizeof(Contacto));
        (*contador)++;
    }
}

int listar(Contacto *lista, int contador)
{
    char *arr[contador];
    int opc = 0;
    for (int i = 0; i < contador; i++)
    {
        char *tmp = (char *)malloc(sizeof(char) * 200);
        sprintf(tmp, "%s - %s - %s",
                lista[i].nombre, lista[i].apodo, lista[i].numero);
        arr[i] = tmp;
    }
    opc = showMenu(contador, arr, "Seleccione un contacto");

    for (int i = 0; i < contador; i++)
    {
        free(arr[i]);
    }

    return opc;
}

int main()
{
    Contacto *lista = NULL;
    int contador = 0;

    char *opciones[] = {"Agregar", "Llamar", "Listar", "Salir"};
    int seleccion;

    do
    {
        seleccion = showMenu(4, opciones, "Agenda de Contactos");
        if (seleccion == 0)
        {
            // Agregar
            Contacto c;
            strcpy(c.nombre, "Sebastian Huerta");
            strcpy(c.apodo, "Tripoide");
            strcpy(c.numero, "1234567");
            strcpy(c.correo, "tripoide@sebas.com");
            agregar(&lista, &contador, c);

            strcpy(c.nombre, "Rodrigo Cuesta");
            strcpy(c.apodo, "Chino Cochino");
            strcpy(c.numero, "8763487653");
            strcpy(c.correo, "chino@cochino.mx");
            
            agregar(&lista, &contador, c);

            strcpy(c.nombre, "Patricio Duran");
            strcpy(c.apodo, "Pato");
            strcpy(c.numero, "4343123");
            strcpy(c.correo, "pato@cuak.com");
            
            agregar(&lista, &contador, c);

        }
        if (seleccion == 1)
        {
            // Lamar
        }
        if (seleccion == 2)
        {
            // Listar
            listar(lista, contador);
        }

        pausa();

    } while (seleccion != 3);

    return 0;
}
