import pyfirmata
import time
import inspect

if not hasattr(inspect, 'getargspec'):
    inspect.getargspec = inspect.getfullargspec


board = pyfirmata.Arduino('COM3')

it = pyfirmata.util.Iterator(board)
it.start()

def handle_read(*data):
    analog_value = sum(data)
    board.send_sysex(0x04, writePwmValue(2, analog_value))

def writePwmValue(pin, value):
    datasToWrite = []

    datasToWrite.append(pin)
    datasToWrite.append(0) #Canal (hasta 16 canales para el ESP32, hasta 8 canales para el ESP32S2)
    datasToWrite.append(1) #Multiplo de la frecuencia: Hz=0, KHz=1, MHz=2 
    datasToWrite.append(15) #Frecuencia (desde 50 Hz hasta 40 MHz)
    datasToWrite.append(10) #Resolución en bits (de 1 a 15) (10 es 2^10, es decir valores d0 1 hasta 1023)

    v = divmod(value, 127)

    for i in range(1, v[0]):
        datasToWrite.append(127)

    if (v[0] >= 1):
        datasToWrite.append(v[1])
    else:
        datasToWrite.append(value)

    print(datasToWrite)
    return datasToWrite

board.add_cmd_handler(0x02, handle_read)

while True:
    board.send_sysex(0x02, [12])
    time.sleep(0.01)
