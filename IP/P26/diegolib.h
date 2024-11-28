#ifndef __DIEGOLIB_H__
#define __DIEGOLIB_H__

typedef struct Contacto
{
    char nombre[100];
    char numero[20];
    char apodo[50];
    char correo[50];
} Contacto;

void agregar(Contacto **lista, int *contador, Contacto contacto);
void eliminar(Contacto **lista, int *contador, int idx);
void llamar(Contacto *lista, int contador, int idx);
void listar2(Contacto *lista, int contador);
int listar(Contacto *lista, int contador);

#endif