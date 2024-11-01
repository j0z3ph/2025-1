import socket
import sys
import threading

def send_msg(sock):
    while True:
        message = sys.stdin.readline()
        if message.lower().startswith('exit'):
            sock.close()
            exit(0)
        else:
            sock.send(bytes(message, 'utf-8'))
            sys.stdout.write("<Tú>")
            sys.stdout.write(message)
            sys.stdout.flush()

def recv_msg(sock):
    while True:
        try:
            message = sock.recv(BUFFER_SIZE)
        except:
            message = None
        if message:
            print(message.decode('utf-8'))
        else:
            print("Conexión cerrada")
            exit(0)
            break

if __name__ == "__main__":
    host = 'tequila.debugueando.com'  # Nombre del server
    port = 80
    BUFFER_SIZE = 1024  # Usamos un número pequeño para tener una respuesta rápida
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.connect((host, port))
    
    threading.Thread(target=send_msg, args=(server,)).start()  
    threading.Thread(target=recv_msg, args=(server,)).start()
