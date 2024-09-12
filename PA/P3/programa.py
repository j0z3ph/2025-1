"""Author: Yo merengues
date: Hoy mesmo
Un programa
"""

class Persona:
    de_clase = "Soy un cacahuate"
    
    def __init__(self, nombre:str, edad:int) -> None:
        self.nombre = nombre
        self.edad = edad
    
    @classmethod
    def metodo_de_clase(cls):
        print("Holis" + cls.de_clase)
    
    @staticmethod
    def metodo_estatico():
        pass
        
    def __str__(self) -> str:
        return f"Hola, me llamo {self.nombre} y tengo {self.edad} años."
    
    def saluda(self):
        print(f"Hola, me llamo {self.nombre} y tengo {self.edad} años.")

entero = 10

pipol = Persona("",0)
Persona.metodo_de_clase()
#print(pipol)
pipol.saluda()