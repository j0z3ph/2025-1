import pyfirmata
import time
import inspect

if not hasattr(inspect, "getargspec"):
    inspect.getargspec = inspect.getfullargspec

board = pyfirmata.Arduino("/dev/cu.usbserial-0001")

it = pyfirmata.util.Iterator(board)
it.start()
sw = False

def handle_read(*data):
    global sw
    if data[0] == 1:
        sw = True
    else:
        sw = False
    # print(data)

board.add_cmd_handler(0x03, handle_read)

while True:
    board.send_sysex(0x03, [12])
    if sw is True:
        board.send_sysex(0x01, [13, 1])
    else:
        board.send_sysex(0x01, [13, 0])
    time.sleep(0.1)

