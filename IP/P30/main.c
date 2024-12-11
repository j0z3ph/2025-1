/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-12-13
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>
#include "miniwin.h"
#include "serial.h"
#define GRAVITY 1
#define JUMP -10

#define X_OFFSET 3182
#define Y_OFFSET 3165
#define MAX_JOY 4095
#define MIN_JOY 0
#define MAX_X 10
#define MIN_X -10
#define MAX_Y 20
#define MIN_Y -20

int main()
{
    int t, aceleracion = 0;
    bool on = false;
    float x = 150, y = 150;
    int _x = 0;
    int read;

    char *portName = "COM6";
    char command[MAX_DATA_LENGTH];
    char response[MAX_DATA_LENGTH];
    command[0] = '\n';
    SerialPort arduino = initSerialPort(portName, B115200);

    MiniWinImage *hongo = creaImagenYMascaraBMP(".\\hongoNoMask.bmp", ".\\hongomask.bmp");
    // MiniWinImage* hongo = creaImagenBMP(".\\hongo.bmp");
    hongo->pos_x = 150;
    hongo->pos_y = 150;

    hongo->alto = 50;
    hongo->ancho = 50;

    ventana(800, 600);
    titulo("Mi Primer Juego");

    color_fondo(ROJO);

    t = tecla();
    while (t != ESCAPE)
    {
        y += aceleracion;
        aceleracion += GRAVITY;
        if (y + hongo->alto > valto())
            y = valto() - hongo->alto;
        if (x < 0)
        {
            x = 0;
            strcpy(command, "vibra\n");
            writeSerialPort(command, strlen(command), &arduino);
        }
        if (x + hongo->ancho > vancho())
        {
            x = vancho() - hongo->ancho - 1;
            strcpy(command, "vibra\n");
            writeSerialPort(command, strlen(command), &arduino);
        }

        borra();
        color(NEGRO);
        // texto(20,20,"Presione ESC para salir");
        textoExt(20, 20, "Presione ESC para salir", 50, true, true, true, "Arial");
        // texto(50, 150, "Hola");

        // color(VERDE);
        // rectangulo_lleno(x,y,x+50,y+50);
        hongo->pos_x = x;
        hongo->pos_y = y;

        // Imagen TEST
        muestraImagen(hongo);

        refresca();
        t = teclaDown();

        if (t == RETURN)
        {
            on = !on;
            fullscreen(on);
        }

        strcpy(command, "read\n");
        writeSerialPort(command, strlen(command), &arduino);
        read = readSerialPort(response, MAX_DATA_LENGTH, &arduino);

        if (read != 0)
        {

            _x = atoi(response) - X_OFFSET;
            // int y = atoi(response+5) - Y_OFFSET;

            if (_x >= 0)
            {
                _x = (int)((double)_x * ((double)MAX_X / (double)(MAX_JOY - X_OFFSET)));
            }
            else
            {
                _x = (-1) * (int)((double)_x * ((double)MIN_X / (double)(X_OFFSET)));
            }
            if (response[10] == '0')
            {
                aceleracion = JUMP;
                strcpy(command, "vibra\n");
                writeSerialPort(command, strlen(command), &arduino);
            }
        }
        x += _x;

        espera(1000/60);
        strcpy(command, "!vibra\n");
        writeSerialPort(command, strlen(command), &arduino);

        // if(y >= 0) {
        //	y = (int)((double)y * ((double)MAX_Y / (double)(MAX_JOY - Y_OFFSET)));
        // } else {
        //	y = (-1)*(int)((double)y * ((double)MIN_Y / (double)(Y_OFFSET)));
        // }
    }
    eliminaImagen(hongo);
    cierra();
    return 0;
}
