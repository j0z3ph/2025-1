#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diegolib.h"
#include "tools.h"

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

void eliminar(Contacto **lista, int *contador, int idx)
{
    if (*lista != NULL)
    {
        if (*contador == 1)
        {
            free(*lista);
            *contador = 0;
            *lista = NULL;
        }
        else
        {
            memcpy(*lista + idx, *lista + idx + 1,
                   sizeof(Contacto) * (*contador - (idx + 1)));
            *lista = (Contacto *)realloc(*lista,
                                         sizeof(Contacto) * (*contador - 1));
            (*contador)--;
        }
    }
}

void llamar(Contacto *lista, int contador, int idx)
{
    printf("Llamando a %s (%s)...", lista[idx].nombre, lista[idx].numero);
}

void listar2(Contacto *lista, int contador)
{
    for (int i = 0; i < contador; i++)
    {
        printf("%i. %s - %s - %s - %s\n",
               i + 1, lista[i].nombre, lista[i].apodo,
               lista[i].numero, lista[i].correo);
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
