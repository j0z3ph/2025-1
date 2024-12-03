/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "miniwin.hpp"
#define GRAVEDAD 1

using namespace miniwin;

int main()
{
    int t;
    bool ip = false, dp = false;
    float x,y;
    float aceleracion = 0;
    float xr=150, yr=150;
    float clic1;
    bool fs = false;
    MiniWinImage rana("R.bmp","RM.bmp");

    ventana(800, 600);
    titulo("Mi primer ventana");
    t = tecla();
    color_fondo_rgb(56, 100, 50);
    while(t != Teclas::ESCAPE) {
        t = tecla();
        yr+= aceleracion;
        aceleracion += GRAVEDAD;
        raton(x, y);

        // Validaciones
        // Piso
        if(yr + rana.alto() > valto()) {
            aceleracion = 0;
            yr = valto() - rana.alto();
        }

        // Barda derecha
        if(xr + rana.ancho() > vancho()) {
            xr = vancho() - rana.ancho();
        }

        // Barda izquierda
        if(xr < 0) {
            xr = 0;
        }
        
        if(t == Teclas::RETURN) {
            fs = !fs;
            fullscreen(fs);
        }

        if(t == Teclas::ESPACIO) {
            aceleracion = -30;
        }

        rana.posX(xr);
        rana.posY(yr);

        borra();
        muestraImagen(rana);

        color(Colores::ROJO);
        texto(5,5, "Texto", 50, true, true, true, "Arial");
        color(Colores::BLANCO);
        //rectangulo_lleno(xr,yr, xr+100,yr+100);
        circulo(x,y, 20);
        circulo_lleno(x,y,10);
        linea(x-10,y,x-30,y);
        linea(x+10,y,x+30,y);
        linea(x,y-10,x,y-30);
        linea(x,y+10,x,y+30);

        if(raton_boton_izq()){

            texto(x,y,"Bang",50,false, false, false, "Comic Sans MS");
        }

        refresca();

        if(t == Teclas::IZQUIERDA) {
            ip = true;
        }
        if(t == Teclas::DERECHA) {
            dp = true;
        }
        t = teclaUp();
        if(t == Teclas::IZQUIERDA) {
            ip = false;
        }
        if(t == Teclas::DERECHA) {
            dp = false;
        }

        if(ip) {
            xr -= 10;
        }
        if(dp) {
            xr += 10;
        }
        

        espera(1);
    }

    cierra();
    
    return 0;
}
