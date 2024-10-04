import threading

class Cuenta:
    def __init__(self) -> None:
        self.__value = 0
    
    def transfer(self, amount, secondAccount, lock):
        with lock:
            self.__value -= amount
            secondAccount.incrementa(amount, lock)
    
    def incrementa(self, amount, lock):
        with lock:
            self.__value += amount
        
    def getValor(self):
        return self.__value

if __name__ == "__main__":
    lock = threading.Lock()
    guardadito1 = Cuenta()
    guardadito2 = Cuenta()
    
    #guardadito1.incrementa(1000, lock)
    #guardadito1.transfer(500, guardadito2, lock)
    
    thread = threading.Thread(target=guardadito1.transfer, args=(500, guardadito2, lock))
    thread.start()
    thread.join()
    
    print(f"El saldo final es {guardadito1.getValor()}")
    print(f"El saldo final es {guardadito2.getValor()}")
