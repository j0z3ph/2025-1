import pyfirmata
import time
import inspect

if not hasattr(inspect, 'getargspec'):
    inspect.getargspec = inspect.getfullargspec


board = pyfirmata.Arduino('/dev/cu.usbserial-0001')
it = pyfirmata.util.Iterator(board)
it.start()

while True:
    
    board.send_sysex(0x01, [2, 1])
    time.sleep(1)
    board.send_sysex(0x01, [2, 0])
    time.sleep(1)
