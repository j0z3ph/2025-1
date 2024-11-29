/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer miniwin
 * @version 0.1
 * @date 2024-11-28
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include "miniwin.hpp"
#define GRAVEDAD 20

using namespace std;
using namespace miniwin;

int main()
{
    int key, ix = 50, iy = 50;
    float x, y;
    ventana(800, 600);
    titulo("Mi primer Miniwin");
    key = tecla();

    color_fondo(Colores::AZUL);

    while (key != Teclas::ESCAPE)
    {
        key = tecla();
        iy += GRAVEDAD;
        if (iy + 100 > 600)
            iy = 600 - 100;
        raton(x, y);
        borra();

        color(Colores::BLANCO);
        rectangulo_lleno(x, y, x + 20, y + 20);
        rectangulo_lleno(ix, iy, ix + 100, iy + 100);

        refresca();

        espera(1);
    }
    cierra();

    return 0;
}
