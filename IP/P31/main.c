/**
 * @file main.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer venta
 * @version 0.1
 * @date 2024-12-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "miniwin.h"
#define GRAVEDAD 1

int main()
{
    int t;
    float x,y;
    bool fc = false;
    bool ip = false, dp = false;
    float xc=100, yc=100;
    float aceleracion = 0;
    MiniWinImage *link = creaImagenYMascaraBMP("zelda.bmp","zeldam.bmp"); 
    titulo("M primer ventana");
    ventana(800, 600);

    color_fondo_rgb(9, 208, 27);
    //fullscreen(true);
    t = tecla();
    while(t != ESCAPE) {
        t = tecla();
        raton(&x, &y);

        aceleracion += GRAVEDAD;
        yc+=aceleracion;

        if(yc + link->alto > valto()) {
            yc = valto()-link->alto;
            aceleracion = 0;
        }

        if(xc + link->ancho > vancho()) {
            xc = vancho() - link->ancho;
        }

        if(t == RETURN) {
            fc = !fc;
            fullscreen(fc);
        }

        if(t == ESPACIO) {
            aceleracion = -20;;
        }

        if(t == IZQUIERDA) {
            ip = true;
        }
        if(t == DERECHA) {
            dp = true;
        }

        link->pos_x = xc;
        link->pos_y = yc;

        borra();

        color(NEGRO);
        circulo_lleno(x,y, 10);
        circulo(x,y, 20);
        linea(x-30, y, x-5, y);
        linea(x+30, y, x+5, y);
        linea(x, y-30, x, y-5);
        linea(x, y+30, x, y+5);
        color(ROJO);
        if(raton_boton_izq()) {
            textoExt(x+10,y-30,"Poww",40, false, true, false, "Comic Sans MS");
        }

        color(BLANCO);
        //rectangulo_lleno(xc,yc,xc+100,yc+100);
        muestraImagen(link);


        refresca();


        t = teclaUp();
        if(t == IZQUIERDA) {
            ip = false;
        }
        if(t == DERECHA) {
            dp = false;
        }

        if(ip) xc -= 10;
        if(dp) xc += 10;
        espera(1000/60);
    }
    

    cierra();
    
    return 0;
}
