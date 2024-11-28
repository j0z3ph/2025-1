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
#include "diegolib.h"


int main()
{
    Contacto *lista = NULL;
    int contador = 0;
    Contacto c;
    int idx;

    char *opciones[] = {"Agregar", "Llamar", "Listar", "Eliminar", "Salir"};
    int seleccion;

    do
    {
        seleccion = showMenu(5, opciones, "Agenda de Contactos");
        if (seleccion == 0)
        {
            // Agregar
            printf("Ingrese el nombre: ");
            fgets(c.nombre, 100, stdin);
            c.nombre[strlen(c.nombre) - 1] = '\0';
            printf("Ingrese el apodo: ");
            fgets(c.apodo, 50, stdin);
            c.apodo[strlen(c.apodo) - 1] = '\0';
            printf("Ingrese el numero: ");
            fgets(c.numero, 20, stdin);
            c.numero[strlen(c.numero) - 1] = '\0';
            printf("Ingrese el correo: ");
            fgets(c.correo, 50, stdin);
            c.correo[strlen(c.correo) - 1] = '\0';

            agregar(&lista, &contador, c);
        }
        if (seleccion == 1)
        {
            // Lamar
            idx = listar(lista, contador);
            llamar(lista, contador, idx);
        }
        if (seleccion == 2)
        {
            // Listar
            listar2(lista, contador);
        }
        if (seleccion == 3)
        {
            // eliminar
            idx = listar(lista, contador);
            eliminar(&lista, &contador, idx);
        }

        pausa();

    } while (seleccion != 4);

    return 0;
}
