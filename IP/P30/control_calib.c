/**
 * @file lectura_analog.c
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief
 * @version 0.1
 * @date 2023-11-27
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "serial.h"
#include <string.h>
#include <stdio.h>
#define X_OFFSET 3182
#define Y_OFFSET 3165
#define MAX_JOY 4095
#define MIN_JOY 0
#define MAX_X 20
#define MIN_X -20
#define MAX_Y 20
#define MIN_Y -20

int main()
{
	char *portName = "COM4";
	char command[MAX_DATA_LENGTH];
	char response[MAX_DATA_LENGTH];
	int maxX = 0;
	int maxY = 0;
	int x;
	int y;
	command[0] = '\n';
	SerialPort arduino = initSerialPort(portName, B115200);
	printf("Conectando");
	while (!isConnected(&arduino))
	{
		Sleep(100);
		printf(".");
		arduino = initSerialPort(portName, B115200);
	}
	if (isConnected(&arduino))
		printf("\nConectado al puerto %s\n", portName);

	while (isConnected(&arduino))
	{
		strcpy(command, "read\n");
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(1);
		readSerialPort(response, MAX_DATA_LENGTH, &arduino);

		// printf("%s", response);

		// continue;

		// maxX = (maxX + atoi(response)) / 2;
		// maxY = (maxY + atoi(response + 5)) / 2;

		// printf("Pomedio X: %5i - Pomedio Y: %5i\n", maxX, maxY);
		// continue;

		x = atoi(response) - X_OFFSET;
		y = atoi(response + 5) - Y_OFFSET;

		if (x >= 0)
		{
			x = (int)((double)x * ((double)MAX_X / (double)(MAX_JOY - X_OFFSET)));
		}
		else
		{
			x = (-1) * (int)((double)x * ((double)MIN_X / (double)(X_OFFSET)));
		}

		if (y >= 0)
		{
			y = (int)((double)y * ((double)MAX_Y / (double)(MAX_JOY - Y_OFFSET)));
		}
		else
		{
			y = (-1) * (int)((double)y * ((double)MIN_Y / (double)(Y_OFFSET)));
		}

		printf("%i - %i\n", x, y);

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
	closeSerial(&arduino);
	return 0;
}
