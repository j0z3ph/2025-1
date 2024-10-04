import time
import concurrent.futures

def thread_function(name):
    print(f"Thread {name}: inicio")
    time.sleep(5)
    print(f"Thread {name}: fin")

if __name__ == "__main__":
    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as executor:
        executor.map(thread_function, [f"Hilo {i}" for i in range(3)])

