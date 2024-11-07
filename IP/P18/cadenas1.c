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
#include"bibfunciones.h"

int main()
{
    char cadena[] = "Jose Luis Cruz Mora";
    char otraCadena[100];

    sprintf(otraCadena, "%i - ", tamanioCadena(cadena));
    puts(otraCadena);
    

    concatenar(otraCadena, cadena);
    puts(otraCadena);

    minusculas(cadena);
    puts(cadena);
    mayusculas(cadena);
    puts(cadena);

    return 0;
}
