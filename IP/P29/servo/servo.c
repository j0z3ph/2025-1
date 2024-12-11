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
		printf("Angulo [0-180/q]: ");
		fgets(command, MAX_DATA_LENGTH, stdin);
		if(command[0] == 'q' || command[0] == 'Q') break;
		writeSerialPort(command, strlen(command), &arduino);
		Sleep(1);
	}
	closeSerial(&arduino);
	return 0;
}
