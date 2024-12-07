/**
 * @file serial.h
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Serial communication for Arduino device
 * @version 0.1
 * @date 2023-08-23
 *
 * @copyright Copyright (c) 2023
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SERIAL_ARDUINO_H__
#define __SERIAL_ARDUINO_H__ 1

#define ARDUINO_WAIT_TIME 2000
#define MAX_DATA_LENGTH 255

typedef enum BaudRate
{
    B0 = 0,
    B50 = 50,
    B75 = 75,
    B110 = 110,
    B134 = 134,
    B150 = 150,
    B200 = 200,
    B300 = 300,
    B600 = 600,
    B1200 = 1200,
    B1800 = 1800,
    B2400 = 2400,
    B4800 = 4800,
    B9600 = 9600,
    B19200 = 19200,
    B38400 = 38400,
    B7200 = 7200,
    B14400 = 14400,
    B28800 = 28800,
    B57600 = 57600,
    B76800 = 76800,
    B115200 = 115200,
    B230400 = 230400
} BaudRate;

#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Handler
{
    HANDLE handler;
    bool connected;
    COMSTAT status;
    DWORD errors;
} SerialPort;
#else
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <getopt.h>
typedef struct Handler
{
    int handler;
    bool connected;
} SerialPort;
#endif

/// @brief Abre una conexion serial con otro dispositivo.
/// @param portName Nombre del puerto.
/// @param br Baud rate o velocidad de conexion (debe ser el mismo que el otro dispositivo).
/// @return Estructura que representa la conexion.
SerialPort initSerialPort(const char *portName, BaudRate br);
#ifdef _WIN32
/// @brief Lee una cadena de texto por el puerto serie.
/// @param buffer Variable donde se escribirá la cadena leida.
/// @param buf_size Tamaño máximo de la cadena a leer.
/// @param handler Puerto serie.
/// @return Total de bytes leidos.
int readSerialPort(char *buffer, unsigned int buf_size, SerialPort *handler);
#else
/// @brief Lee una cadena de texto por el puerto serie.
/// @param buffer Variable donde se escribirá la cadena leida.
/// @param buf_size Tamaño máximo de la cadena a leer.
/// @param handler Puerto serie.
/// @return Total de bytes leidos.
int readSerialPort(char *buffer, unsigned int buf_size, SerialPort *handler);
#endif
/// @brief Escribe una cadena de texto en el puerto serie.
/// @param buffer Cadena de texto a enviar.
/// @param buf_size Tamaño de la cadena.
/// @param handler Puerto serie.
/// @return \c true si  la cadena se envió. \c false en caso de error.
bool writeSerialPort(const char *buffer, unsigned int buf_size, SerialPort *handler);
/// @brief Permite saber si un puerto serie esta conectado.
/// @param handler Puerto serie.
/// @return \c true si esta conectado. \c false si no hay conexión.
bool isConnected(SerialPort *handler);
/// @brief Cierra el puerto serie.
/// @param handler Puerto serie.
void closeSerial(SerialPort *handler);

#ifndef _WIN32
/// @brief Detiene la ejecución del código por \e val milisegundos.
/// @param val Valor en milisegundos.
void Sleep(int val);
#endif

#endif