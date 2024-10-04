import threading
import time

def thread_function(name):
    print(f"Thread {name}: inicio")
    time.sleep(5)
    print(f"Thread {name}: fin")

if __name__ == "__main__":
    print("Main: Inicio del hilo principal")
    x = threading.Thread(target=thread_function, args=("Hilo 1",), daemon=True)
    print("Main: Antes de iniciar el hilo 1")
    x.start()
    print("Main: Hilo 1 iniciado")
    print("Main: Fin del main")
    
    