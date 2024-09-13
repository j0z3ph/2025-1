"""Author: Yo merengues
date: Hoy mesmo
Un programa
"""
from multimethod import multimethod

class Persona:
    de_clase = "Soy un cacahuate"
    
    def __init__(self, nombre:str, edad:int) -> None:
        self.__nombre = nombre
        self.__edad = edad
    
    @property    
    def nombre(self):
        return self.__nombre
    
    @nombre.setter
    def nombre(self, name: str):
        self.__nombre = name
    
    @property    
    def edad(self):
        return self.__edad
    
    @edad.setter
    def edad(self, edad:int):
        self.__edad = edad
        
    
    @classmethod
    def metodo_de_clase(cls):
        print("Holis" + cls.de_clase)
    
    @staticmethod
    def metodo_estatico():
        pass
        
    def __str__(self) -> str:
        return f"Hola, me llamo {self.__nombre} y tengo {self.__edad} años."
    
    @multimethod
    def saluda(self):
        print(f"Hola, me llamo {self.__nombre} y tengo {self.__edad} años.")

    @multimethod
    def saluda(self, msg:str):
        print(msg)
        
    def __len__(self):
        return 10
    
    def __add__(self, obj):
        return self.__edad + obj.edad

class Alumno(Persona):
    pass

entero = 10

julio = Alumno("",0)
julio.edad = 10
print(julio.edad)

pipol = Persona("",10)

Persona.metodo_de_clase()
#print(pipol)
pipol.nombre = "Jose"
print(pipol.nombre)
pipol.saluda("Un mensajito")

print(pipol + julio)