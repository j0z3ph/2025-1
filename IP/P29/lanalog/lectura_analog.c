#include "serial.h"
#include <string.h>

int main()
{
	char *portName = "COM4";
	char command[MAX_DATA_LENGTH];
	char response[MAX_DATA_LENGTH];
	int delay = 0;
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
		strcpy(command, "analog\n");
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(1);
		readSerialPort(response, MAX_DATA_LENGTH, &arduino);
		// printf("%s", response);
		// continue;
		
		delay = ((900 * atoi(response)) / 4095) + 100;
		// printf("%i\n", delay);
		strcpy(command, "on\n");
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(delay);
		strcpy(command, "off\n");
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(delay);
	}
	closeSerial(&arduino);
	return 0;
}
