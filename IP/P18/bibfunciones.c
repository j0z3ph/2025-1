#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void minusculas(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 65 && cadena[i] <= 90)
        {
            // Es una letra mayuscula
            cadena[i] = cadena[i] + 32;
        }
    }
}

void mayusculas(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 97 && cadena[i] <= 122)
        {
            // Es una letra minuscula
            cadena[i] -= 32;
        }
    }
}

int tamanioCadena(char *cadena)
{
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
        contador++;
    return contador;
}

void concatenar(char *cadenauno, char *cadenados)
{
    int final = tamanioCadena(cadenauno);
    for (int i = 0; cadenados[i] != '\0'; i++, final++)
    {
        cadenauno[final] = cadenados[i];
    }
    cadenauno[final] = '\0';
}


void dereversaPapi(char *cadena) {
    for (int i = tamanioCadena(cadena); i >= 0; i--)
    {
        putc(cadena[i], stdout);
    }
}
