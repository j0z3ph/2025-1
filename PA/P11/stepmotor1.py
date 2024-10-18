import pyfirmata
import time
import inspect

if not hasattr(inspect, 'getargspec'):
    inspect.getargspec = inspect.getfullargspec
        
board=pyfirmata.Arduino('/dev/cu.usbmodem14101')

it = pyfirmata.util.Iterator(board)
it.start()

pin_1 = board.get_pin('d:8:o')
pin_2 = board.get_pin('d:9:o')
pin_3 = board.get_pin('d:10:o')
pin_4 = board.get_pin('d:11:o')
cont = 0
dir = 1
MAX = 4096

# Movimiento normal
def move(step: int):
    if step == 0:
        pin_1.write(1)
        pin_2.write(1)
        pin_3.write(0)
        pin_4.write(0)
    elif step == 1:
        pin_1.write(0)
        pin_2.write(1)
        pin_3.write(1)
        pin_4.write(0)
    elif step == 2:
        pin_1.write(0)
        pin_2.write(0)
        pin_3.write(1)
        pin_4.write(1)
    elif step == 3:
        pin_1.write(1)
        pin_2.write(0)
        pin_3.write(0)
        pin_4.write(1)

def reset():
    pin_1.write(0)
    pin_2.write(0)
    pin_3.write(0)
    pin_4.write(0)

try:
    while True:
        move(cont % 4)
        if dir == 1 and cont < MAX:
            cont += 1
        else:
            dir = -1
        if dir == -1 and cont > 0:
            cont -= 1
        else:
            dir = 1
        
        time.sleep(1/50)
        
except KeyboardInterrupt:
    reset()