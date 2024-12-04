/**
 * @file main.cpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer ventana
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include"miniwin.hpp"
#define GRAVEDAD 1

using namespace miniwin;

int main()
{
    int t;
    bool fs = false, ip = false, dp = false;
    float x, y;
    float xr = 100, yr = 100;
    float aceleracion = 0;
    MiniWinImage conejo("C.bmp", "CM.bmp");
    


    ventana(800, 600);
    titulo("Mi primer ventana");
    t = tecla();

    color_fondo_rgb(150,126,106);

    while(t != Teclas::ESCAPE) {
        t = tecla();

        

        yr += aceleracion;
        aceleracion += GRAVEDAD;

        if(yr + conejo.alto() > valto()) {
            yr = valto() - conejo.alto();
            aceleracion = 0;
        }

        raton(x,y);


        if(t == Teclas::RETURN) {
            fs = !fs;
            fullscreen(fs);
        }
        if(t == Teclas::ESPACIO) {
            aceleracion = -20;
        }

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

        if(ip) xr -= 10;
        if(dp) xr += 10;

        // Barda derecha
        if(xr + conejo.ancho() > vancho()) {
            xr = vancho() - conejo.ancho();
        }
        // Barda izquierda
        if(xr < 0) {
            xr = 0;
        }

        conejo.posX(xr);
        conejo.posY(yr);

        borra();
        color(Colores::ROJO);
        texto(10,10, "Texto", 60, true, true, true, "Comic Sans MS");

        color(Colores::BLANCO);
        //rectangulo_lleno(xr,yr,xr+100,yr+100);
        muestraImagen(conejo);


        circulo(x,y, 20);
        circulo_lleno(x,y, 10);
        linea(x-15,y,x-30,y);
        linea(x+15,y,x+30,y);
        linea(x,y-15,x,y-30);
        linea(x,y+15,x,y+30);

        if(raton_boton_izq()) {
            color(Colores::VERDE);
            texto(x,y,"AAAAHHH!!!", 50, false, false, false, "Impact");
        }
        
        

        refresca();


        espera(1);
    }

    cierra();

    return 0;
}
