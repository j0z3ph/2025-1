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
#include "serial.h"
#define GRAVEDAD 1
#define CX 3180
#define CY 3165

int main()
{
    int t, _x, _y;
    float x = 100,y = 100;
    bool fc = false, boton = false;
    bool ip = false, dp = false;
    float xc=100, yc=100;
    float aceleracion = 0;
    char comando[MAX_DATA_LENGTH];
    char respuesta[MAX_DATA_LENGTH];
    MiniWinImage *link = creaImagenYMascaraBMP("zelda.bmp","zeldam.bmp"); 
    titulo("M primer ventana");
    ventana(800, 600);


    // Serial
    SerialPort control = initSerialPort("COM4", B115200);


    color_fondo_rgb(9, 208, 27);
    //fullscreen(true);
    t = tecla();
    while(t != ESCAPE) {
        t = tecla();
        //raton(&x, &y);

        // Leo los valor del control
        sprintf(comando, "read\n");
        writeSerialPort(comando, strlen(comando), &control);
        readSerialPort(respuesta, MAX_DATA_LENGTH, &control);

        _x = atoi(respuesta) - CX;
        _y = atoi(respuesta + 5) - CY;
        boton = respuesta[10] == '1' ? false : true;


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

        _x = _x >=0 ? (_x * 20) /(4096-CX) : (_x * 20) /(CX);
        _y = _y >=0 ? (_y * 20) /(4096-CY) : (_y * 20) /(CY);
        x+= _x;
        y+= _y;
        sprintf(comando, "%i-%i", _x, _y);
        texto(10,10, comando);
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
        if(boton) {
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
