from math import sqrt, ceil, floor


def saluda():
    print("Hola cara de bola")
    
def imprime(mensaje:str):
    print(mensaje)
    
def suma_chida(*numeros):
    sum = 0
    for val in numeros:
        sum += val
    return sum

def suma(a:int=8, b:int = 10) -> int:
    """Suma dos numeros

    Args:
        a (int): Numero uno
        b (int): Numero dos

    Returns:
        int: La suma
    """
    return a + b
    
saluda()
imprime("Adios!! :'(")

la_suma = lambda a,b: a+b

imprime(f"La suma {la_suma(4,5)}")
imprime(f"La suma {suma_chida(1,2,3,4,5,6,7,8,9,12)}")