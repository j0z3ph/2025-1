/**
 * @file serial.c
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
#include "serial.h"

#ifdef _WIN32
SerialPort initSerialPort(const char *portName, BaudRate br)
{
    SerialPort handler;
    handler.connected = false;
    handler.handler = CreateFileA((LPCSTR)portName,
                                  GENERIC_READ | GENERIC_WRITE,
                                  0,
                                  NULL,
                                  OPEN_EXISTING,
                                  0,
                                  NULL);
    if (handler.handler == INVALID_HANDLE_VALUE)
    {
        if (GetLastError() == ERROR_FILE_NOT_FOUND)
        {
            printf("ERROR: Handle was not attached. Reason : %s not available\n", portName);
        }
        else
        {
            printf("ERROR!!!\n");
        }
    }
    else
    {
        DCB dcbSerialParameters = {0};

        if (!GetCommState(handler.handler, &dcbSerialParameters))
        {
            printf("Failed to get current serial parameters\n");
        }
        else
        {
            dcbSerialParameters.BaudRate = br;
            dcbSerialParameters.ByteSize = 8;
            dcbSerialParameters.StopBits = ONESTOPBIT;
            dcbSerialParameters.Parity = NOPARITY;
            dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(handler.handler, &dcbSerialParameters))
            {
                printf("ALERT: could not set serial port parameters\n");
            }
            else
            {
                handler.connected = true;
                PurgeComm(handler.handler, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(ARDUINO_WAIT_TIME);
            }
        }
    }
    return handler;
}

int readSerialPort(char *buffer, unsigned int buf_size, SerialPort *handler)
{
    char c;
    unsigned int bytesRead = 0;
    ClearCommError(handler->handler, &handler->errors, &handler->status);
    memset((void *)buffer, 0, buf_size);

    if (handler->status.cbInQue > 0)
    {
        while (ReadFile(handler->handler, &c, 1, NULL, NULL))
        {
            if (bytesRead >= buf_size)
            {
                bytesRead--;
                break;
            }
            buffer[bytesRead++] = c;
            if (c == '\n')
            {
                break;
            }
        }
        buffer[bytesRead] = '\0';
    }

    return bytesRead;
}

bool writeSerialPort(const char *buffer, unsigned int buf_size, SerialPort *handler)
{
    DWORD bytesSend;

    if (!WriteFile(handler->handler, buffer, buf_size, &bytesSend, 0))
    {
        ClearCommError(handler->handler, &handler->errors, &handler->status);
        return false;
    }
    return true;
}

bool isConnected(SerialPort *handler)
{
    if (!ClearCommError(handler->handler, &handler->errors, &handler->status))
    {
        handler->connected = false;
    }

    return handler->connected;
}

void closeSerial(SerialPort *handler)
{
    CloseHandle(handler->handler);
}

#else

SerialPort initSerialPort(const char *portName, BaudRate br)
{
    SerialPort handler;
    handler.connected = false;

    handler.handler = open(portName, O_RDWR | O_NOCTTY | O_SYNC);
    if (handler.handler < 0)
    {
        printf("Error %d opening %s: %s", errno, portName, strerror(errno));
    }
    else
    {
        struct termios tty;
        if (tcgetattr(handler.handler, &tty) != 0)
        {
            printf("Error %d from tcgetattr", errno);
        }

        cfsetospeed(&tty, br);
        cfsetispeed(&tty, br);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8; // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        // tty.c_iflag &= ~IGNBRK; // disable break processing
        tty.c_lflag = ICANON; // no signaling chars, no echo,
                              // no canonical processing
        // tty.c_oflag = 0;        // no remapping, no delays
        tty.c_cc[VMIN] = MAX_DATA_LENGTH; // read block until get MAX_DATA_LENGTH or TIMEOUT
        tty.c_cc[VTIME] = 5;              // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);   // ignore modem controls,
                                           // enable reading
        tty.c_cflag &= ~(PARENB | PARODD); // shut off parity
        tty.c_cflag |= 0;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr(handler.handler, TCSANOW, &tty) != 0)
        {
            printf("Error %d from tcsetattr", errno);
        }
        handler.connected = true;
    }

    return handler;
}

int readSerialPort(char *buffer, unsigned int buf_size, SerialPort *handler)
{
    int n = read(handler->handler, (void *)buffer, buf_size);
    buffer[n] = '\0';
    return n;
}

bool writeSerialPort(const char *buffer, unsigned int buf_size, SerialPort *handler)
{
    write(handler->handler, buffer, buf_size);
    return true;
}

bool isConnected(SerialPort *handler)
{
    return handler->connected;
}

void closeSerial(SerialPort *handler)
{
    close(handler->handler);
}

void Sleep(int val)
{
    usleep(val * 1000);
}
#endif