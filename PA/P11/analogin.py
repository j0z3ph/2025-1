import pyfirmata
import time
import inspect

if not hasattr(inspect, 'getargspec'):
    inspect.getargspec = inspect.getfullargspec


board = pyfirmata.Arduino('COM4')

it = pyfirmata.util.Iterator(board)
it.start()

analog_input = board.get_pin('a:0:i')
led = board.get_pin('d:13:o')

while True:
    analog_value = analog_input.read()
    #print(analog_value)
    if analog_value is not None:    
        delay = analog_value
        led.write(1)
        time.sleep(delay)
        led.write(0)
        time.sleep(delay)
    else:
        time.sleep(0.1)
