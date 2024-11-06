import socket
import threading

class Cliente:
    name = ""
    conn = None
    addr = None

def clientthread(conn, addr):
    conn.send(bytes(f"Bienvenido {addr}\n", 'utf-8'))
    while True:
        #try:
            message = conn.recv(BUFFER_SIZE)
            if message:
                print(f"<{addr[0]}> {message}")
                msg = message.decode('utf-8')
                # Mensajes especiales (comandos)
                if msg.startswith('<name>'):
                    setName(conn, msg.removeprefix('<name>'))
                elif msg.startswith('<command>'):
                    broadcast(msg + '\n', conn)
                else:
                    # Reenviamos el mensaje recibido a todos los demás clientes.
                    message_to_send = f"<{getName(conn)}> {message.decode('utf-8')}\n"
                    broadcast(message_to_send, conn)
            else:
                remove(conn)
        #except:
        #    break

def setName(connection, name:str):
    for client in list_of_clients:
        if client.conn == connection:
            client.name = name
            break

def getName(connection) -> str:
    for client in list_of_clients:
        if client.conn == connection:
            return client.name
    return ""

def broadcast(message, connection):
    for client in list_of_clients:
        if client.conn != connection:
            try:
                client.conn.send(bytes(message, 'utf-8'))
            except:
                client.conn.close()
                remove(client)

def remove(connection):
    if connection in list_of_clients:
        list_of_clients.remove(connection)

if __name__ == "__main__":
    #host = socket.gethostname()  # Esta función nos da el nombre de la máquina
    host = "0.0.0.0"
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
            nuevo_cliente = Cliente()
            nuevo_cliente.conn = conn
            nuevo_cliente.addr = addr
            #list_of_clients.append(conn)  # Agregamos a la lista de clientes
            list_of_clients.append(nuevo_cliente)  # Agregamos a la lista de clientes
            print(f"Cliente conectado: {addr}")
            # Creamos y ejecutamos el hilo para atender al cliente
            threading.Thread(target=clientthread, args=(conn, addr)).start()
    except KeyboardInterrupt:
        print("Caught keyboard interrupt, exiting")
    finally:
        conn.close()
        server.close()   
    print("Conexión terminada.")
