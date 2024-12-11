/**
 * @file shooter.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2024-12-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include "miniwin.h"
#include "serial.h"

#define X_OFFSET 3182
#define Y_OFFSET 3165
#define MAX_JOY 4095
#define MIN_JOY 0
#define MAX_X 15
#define MIN_X -15
#define MAX_Y 15
#define MIN_Y -15

int main()
{
    int t, read;
    bool on = false;
    float x = 400, y = 300;
    int _x = 0, _y = 0;

    char *portName = "COM4";
    char command[MAX_DATA_LENGTH];
    char response[MAX_DATA_LENGTH];
    command[0] = '\n';
    SerialPort arduino = initSerialPort(portName, B115200);

    ventana(800, 600);
    titulo("Mi Primer Juego");

    color_fondo(ROJO);

    t = tecla();
    while (t != ESCAPE)
    {
        if (x > vancho())
            x = vancho();
        if (x < 0)
            x = 0;
        if (y > valto())
            y = valto();
        if (y < 0)
            y = 0;

        borra();
        color(NEGRO);
        textoExt(20, 20, "Presione ESC para salir", 50, true, true, true, "Arial");

        color(BLANCO);
        circulo(x, y, 7);
        circulo(x, y, 15);
        linea(x, y - 10, x, y - 2);
        linea(x, y + 2, x, y + 10);
        linea(x - 10, y, x - 2, y);
        linea(x + 2, y, x + 10, y);

        refresca();
        t = teclaDown();

        if (t == RETURN)
        {
            on = !on;
            fullscreen(on);
        }

        strcpy(command, "read\n");
        writeSerialPort(command, strlen(command), &arduino);
        Sleep(1);
        read = readSerialPort(response, MAX_DATA_LENGTH, &arduino);

        if (read != 0)
        {

            _x = atoi(response) - X_OFFSET;
            _y = atoi(response + 5) - Y_OFFSET;

            if (_x >= 0)
            {
                _x = (int)((double)_x * ((double)MAX_X / (double)(MAX_JOY - X_OFFSET)));
            }
            else
            {
                _x = (-1) * (int)((double)_x * ((double)MIN_X / (double)(X_OFFSET)));
            }
            if (_y >= 0)
            {
                _y = (int)((double)_y * ((double)MAX_Y / (double)(MAX_JOY - Y_OFFSET)));
            }
            else
            {
                _y = (-1) * (int)((double)_y * ((double)MIN_Y / (double)(Y_OFFSET)));
            }
            if (response[10] == '0')
            {
                strcpy(command, "vibra\n");
                writeSerialPort(command, strlen(command), &arduino);
            }
            else
            {
                strcpy(command, "!vibra\n");
                writeSerialPort(command, strlen(command), &arduino);
            }
        }
        x += _x;
        y += _y;

        espera(1);
    }
    cierra();
    closeSerial(&arduino);
    return 0;
}
