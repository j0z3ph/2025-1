import time
import concurrent.futures
import threading

class Cuenta:
    def __init__(self) -> None:
        self.__value = 0
        self.__lock = threading.Lock()
    
    def incrementa(self):
        self.__lock.acquire()
        temp = self.__value
        temp += 1
        time.sleep(0.01)
        self.__value = temp
        self.__lock.release()
        
    def getValor(self):
        return self.__value

if __name__ == "__main__":
    guardadito = Cuenta()
    
    with concurrent.futures.ThreadPoolExecutor(max_workers=100) as executor:
        for index in range(100):
           executor.submit(guardadito.incrementa)
        executor.shutdown(wait=True)
    print(f"El saldo final es {guardadito.getValor()}")
    
