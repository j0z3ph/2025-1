/**
 * @file uniones.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Uniones?
 * @version 0.1
 * @date 2024-11-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>

typedef struct Estructura
{
    int entero;
    float flotante;
    double doble;
    char caracter;
} Estructura;

typedef union Union
{
    int entero;
    float flotante;
    double doble;
    char caracter;
} Union;

int main()
{
    Estructura e;
    printf("%lu\n", sizeof(Estructura));
    e.caracter = 'h';
    printf("%c\n", e.caracter);
    e.doble = 2.5;
    printf("%lf\n", e.doble);
    e.entero = 10;
    printf("%i\n", e.entero);
    printf("%lf\n", e.doble);
    e.flotante = 5.6f;
    printf("%f\n", e.flotante);
    printf("%c\n", e.caracter);

    Union u;
    printf("%lu\n", sizeof(Union));
    u.caracter = 'h';
    printf("%c\n", u.caracter);
    u.doble = 2.5;
    printf("%lf\n", u.doble);
    u.entero = 10;
    printf("%i\n", u.entero);
    printf("%lf\n", u.doble);
    u.flotante = 5.6f;
    printf("%f\n", u.flotante);
    printf("%c\n", u.caracter);

    return 0;
}
