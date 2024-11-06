/**
 * @file cadenas1.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Ejemplo de cadenas
 * @version 0.1
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int tamanioCadena(char *cadena)
{
    int contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++)
        contador++;
    return contador;
}

void concatenar(char *cadenauno, char * cadenados) {
    int final = tamanioCadena(cadenauno);
    for (int i = 0; cadenados[i] != '\0'; i++, final++)
    {
        cadenauno[final] = cadenados[i];
    }
    cadenauno[final] = '\0';
}

int main()
{
    char *cadena = "Jose Luis Cruz Mora";
    char otraCadena[100];

    sprintf(otraCadena, "%i - ", tamanioCadena(cadena));
    puts(otraCadena);
    

    concatenar(otraCadena, cadena);
    puts(otraCadena);
    return 0;
}
