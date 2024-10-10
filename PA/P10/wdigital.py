import serial

device = serial.Serial('/dev/cu.usbmodem14101', 115200)

if device.is_open:
    command = "n"
    while not command.startswith("q"):
        command = input('Escriba un comando[on/off/q]:')
        device.write((command + "\n").encode())
        response = device.readline().decode()
        print(response)
        
    device.close()
