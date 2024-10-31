import socket
import threading

def clientthread(conn, addr):
    conn.send(bytes(f"Bienvenido {addr}", 'utf-8'))
    while True:
        try:
            message = conn.recv(BUFFER_SIZE).decode('utf-8')
            if message:
                print(f"<{addr[0]}> {message}")
                # Reenviamos el mensaje recibido a todos los demás clientes.
                message_to_send = f"<{addr[0]}> {message}"
                broadcast(message_to_send, conn)
            else:
                remove(conn)
        except:
            break

def broadcast(message, connection):
    for clients in list_of_clients:
        if clients != connection:
            try:
                clients.send(bytes(message, 'utf-8'))
            except:
                clients.close()
                remove(clients)

def remove(connection):
    if connection in list_of_clients:
        list_of_clients.remove(connection)

if __name__ == "__main__":
    host = 'localhost'  # Esta función nos da el nombre de la máquina
    port = 65535
    BUFFER_SIZE = 1024  # Usamos un número pequeño para tener una respuesta rápida
    # Creamos un socket TCP
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((host, port))
    server.listen(100)  # Escuchamos hasta 100 clientes
    list_of_clients = []  # Lista de clientes conectados
    print(f"Escuchando conexiones en: {(host, port)}")
    try:
        while True:
            conn, addr = server.accept()
            list_of_clients.append(conn)  # Agregamos a la lista de clientes
            print(f"Cliente conectado: {addr}")
            # Creamos y ejecutamos el hilo para atender al cliente
            threading.Thread(target=clientthread, args=(conn, addr)).start()
    except KeyboardInterrupt:
        print("Caught keyboard interrupt, exiting")
    finally:
        conn.close()
        server.close()   
    print("Conexión terminada.")
