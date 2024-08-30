cadena = "Buenas noches Julio {2}, {0}, {1}"
print(cadena)
var = cadena.format(3, "holis", True)

print("No se{1}, gato {0} naranja".format(4, var))

PI = 3.1416
var = 5

print(f"Otra cadena {PI} - {PI} aqui va otra cosa {var:^010}")