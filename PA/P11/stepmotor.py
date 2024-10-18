import pyfirmata
import time
import inspect
import steplib

if not hasattr(inspect, 'getargspec'):
    inspect.getargspec = inspect.getfullargspec
        
board=pyfirmata.Arduino('/dev/cu.usbmodem101')

it = pyfirmata.util.Iterator(board)
it.start()

motor = steplib.Stepper(64, board, 8, 9, 10, 11)
motor.set_speed(100)

try:
    while True:
        motor.step(4096)
        motor.step(-4096)
        
except KeyboardInterrupt:
    motor.off()