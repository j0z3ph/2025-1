from abc import ABCMeta
from abc import abstractmethod

class Figura(metaclass=ABCMeta):
    @abstractmethod
    def area(sefl):
        pass
    
class Cuadrado(Figura):
    def area(sefl):
        return 0

c1 = Cuadrado()


#print(c1.area())
circulo = Figura()