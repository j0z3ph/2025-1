import threading
import time

def thread_function(name):
    print(f"Thread {name}: inicio")
    time.sleep(5)
    print(f"Thread {name}: fin")

if __name__ == "__main__":
    hilos = list()
    for i in range(3):
        x = threading.Thread(target=thread_function, args=(f"Hilo {i}",))
        hilos.append(x)
        x.start()
    
    for _, thread in enumerate(hilos):
        thread.join()

