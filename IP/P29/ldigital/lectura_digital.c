#include "serial.h"
#include <string.h>

int main()
{
	char *portName = "COM4";
	char command[MAX_DATA_LENGTH];
	char response[MAX_DATA_LENGTH];
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
	
	while (isConnected(&arduino) && command[0] != 'q') {
		readSerialPort(response, MAX_DATA_LENGTH, &arduino);
		puts(response);
		Sleep(1);
		if (response[0] == '1') {
			strcpy(command, "on\n");
			writeSerialPort(command, strlen(command), &arduino);
		}
		else if (response[0] == '0') {
			strcpy(command, "off\n");
			writeSerialPort(command, strlen(command), &arduino);
		}
	}
	closeSerial(&arduino);
	return 0;
}
