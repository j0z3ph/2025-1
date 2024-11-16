/**
 * @file prog.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-11-15
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include "tools.h"

int main()
{
    char *opciones[] = {
        "Agregar",
        "Llamar",
        "Listar",
        "Eliminar",
        "Salir"};
    int opc;
    opc = showMenu(5, opciones, "Arreglo Dinamico");

    printf("%i\n", opc);

    return 0;
}
