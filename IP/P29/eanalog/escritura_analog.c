#include "serial.h"
#include <string.h>

int main()
{
	char *portName = "COM4";
	char command[MAX_DATA_LENGTH];
	char response[MAX_DATA_LENGTH];
	int val = 0;
	command[0] = '\n';
	SerialPort arduino = initSerialPort(portName, B115200);
	printf("Conectando");
	while (!isConnected(&arduino)) {
		Sleep(100);
		printf(".");
		arduino = initSerialPort(portName, B115200);
	}
	if (isConnected(&arduino))
		printf("\nConectado al puerto %s\n", portName);

	while (isConnected(&arduino)) {
		strcpy(command, "analog\n");
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(1);
		readSerialPort(response, MAX_DATA_LENGTH, &arduino);
		// puts(response);
		val = (atoi(response) * 255) / 4096;
		sprintf(command, "%d\n", val);
		writeSerialPort(command, strlen(command), &arduino);
	}
	closeSerial(&arduino);
	return 0;
}
