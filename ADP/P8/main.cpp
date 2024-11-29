/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include "miniwin.hpp"

using namespace std;
using namespace miniwin;

int main() {
    int key;
    ventana(800,600);
    titulo("Mi ventana");
    //MiniWinImage img("");
    

    color_fondo(Colores::AZUL);
    key = tecla();

    while (key != Teclas::ESCAPE) {
        key = tecla();
        borra();

        color(Colores::BLANCO);
        rectangulo_lleno(10,10,200,200);



        refresca();
        espera(1);
    }

    cierra();

    return 0;
}