'''
Jose Luis Cruz
Programa 2
'''

from funciones import imprime

imprime('Holis')

try:
    numero = int(input("Querido usuario, ingrese un numero: "))
    if numero > 10:
        print("Mayor a 10")
    else:
        print("Menor a 10")    
except KeyboardInterrupt:
    print("Upss, adios")
except:
    print("Error, tonoto")
else:
    print("adios")
finally:
    print("Fatality")


