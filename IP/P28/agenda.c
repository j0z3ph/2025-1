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
    int id;
    char nombre[100];
    char numero[20];
    char apodo[50];
    char correo[50];
} Contacto;


int main()
{
    FILE *archi;
    Contacto *lista = NULL;
    int contador = 0;
    Contacto c;
    int idx;

    archi = fopen("agenda.bin", "rb+");
    if(archi == NULL) {
        FILE *archi2 = fopen("agenda.bin", "wb");
        if(archi2 == NULL) {
            printf("No se pudo :<");
            return 1;
        }
        fclose(archi2);
    }
    fclose(archi);

    char *opciones[] = {"Agregar", "Llamar", "Listar", "Eliminar", "Salir"};
    int seleccion;

    do
    {
        seleccion = showMenu(5, opciones, "Agenda de Contactos");
        if (seleccion == 0)
        {
            // Agregar
            printf("Ingrese el id: ");
            fgets(c.nombre, 100, stdin);
            c.id = atoi(c.nombre);
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

            archi = fopen("agenda.bin", "rb+");
            fseek(archi, sizeof(Contacto) * (c.id - 1), SEEK_SET);
            fwrite(&c, sizeof(Contacto), 1, archi);
            fclose(archi);
            
        }
        if (seleccion == 1)
        {
            // Lamar
            printf("Lista de contactos\n");
            archi = fopen("agenda.bin", "rb+");
            while(fread(&c, sizeof(Contacto), 1, archi)) {
                if(c.id != 0) {
                    printf("%i - %s (%s)\n", c.id, c.nombre, c.apodo);
                }
            }
            printf("Seleccione el ID a llamar: ");
            scanf("%i", &idx);
            fseek(archi, sizeof(Contacto) * (idx - 1), SEEK_SET);
            fread(&c, sizeof(Contacto), 1, archi);
            if(c.id == 0) {
                printf("No seas tonoto, ese numero no existe >:|");
            } else {
                printf("Llamando a %s (%s)...", c.apodo, c.numero);
            }

            fclose(archi);
        }
        if (seleccion == 2)
        {
            // Listar
            printf("Lista de contactos\n");
            archi = fopen("agenda.bin", "rb+");
            while(fread(&c, sizeof(Contacto), 1, archi)) {
                if(c.id != 0) {
                    printf("%i - %s (%s)\n", c.id, c.nombre, c.apodo);
                }
            }
            fclose(archi);
        }
        if (seleccion == 3)
        {
            // eliminar
            printf("Lista de contactos\n");
            archi = fopen("agenda.bin", "rb+");
            while(fread(&c, sizeof(Contacto), 1, archi)) {
                if(c.id != 0) {
                    printf("%i - %s (%s)\n", c.id, c.nombre, c.apodo);
                }
            }
            printf("Seleccione el ID a eliminar: ");
            scanf("%i", &idx);
            fseek(archi, sizeof(Contacto) * (idx - 1), SEEK_SET);
            fread(&c, sizeof(Contacto), 1, archi);
            fseek(archi, sizeof(Contacto) * (idx - 1), SEEK_SET);
            
            if(c.id == 0) {
                printf("No seas tonoto, ese contacto no existe >:|");
            } else {
                printf("%s ha sido eliminado.", c.apodo);
                memset(&c, 0, sizeof(Contacto));
                fwrite(&c, sizeof(Contacto), 1, archi);
            }
            fclose(archi);
        }

        pausa();

    } while (seleccion != 4);

    return 0;
}
