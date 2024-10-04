import time
import concurrent.futures

class Cuenta:
    def __init__(self) -> None:
        self.__value = 0
    
    def incrementa(self):
        temp = self.__value
        temp += 1
        time.sleep(0.01)
        self.__value = temp
        
    def getValor(self):
        return self.__value

if __name__ == "__main__":
    guardadito = Cuenta()
    
    #for _ in range(100):
    #    guardadito.incrementa()
        
    with concurrent.futures.ThreadPoolExecutor(max_workers=100) as executor:
        for index in range(100):
           executor.submit(guardadito.incrementa)
        executor.shutdown(wait=True)
    print(f"El saldo final es {guardadito.getValor()}")
    
