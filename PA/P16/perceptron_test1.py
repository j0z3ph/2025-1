"""
Perceptron entrenado para ser AND y OR (linealmente separables)
No funciona con XOR (No son linealmente separables)
"""

umbral = -0.5  # umbral de activacion de la neurona (si el resultado es mayor al umbral, la neurona se activa)
taza_aprendizaje = 0.1  # valor que se usara para ajustar los pesos en la fase de aprendizaje
pesos = [0, 0]  # pesos iniciales (w1, w2) (Un peso por cada entrada)

# entradas para entrenar
entradas = [(0, 0), (0, 1), (1, 0), (1, 1)]  # x1, x2 (dos entradas por cada elemento de la lista de entradas)

#salidas_deseadas = [0, 0, 0, 1]  # AND
#salidas_deseadas = [1, 1, 1, 0]  # NAND

#salidas_deseadas = [0, 1, 1, 1]  # OR

salidas_deseadas = [0, 1, 1, 0]  # XOR


def neurona(entrada, pesos):
    # multiplicamos cada entrada por su respectivo peso y los sumamos
    valor = 0
    for idx, x in enumerate(entrada):
        valor += x * pesos[idx]

    # devolvemos 1 si la neurona se activa, 0 si no se activa
    return int(valor + umbral >= 0)


if __name__ == "__main__":
    while True:
        cont_errores = 0

        for idx, entrada in enumerate(entradas):
            resultado = neurona(entrada, pesos)
            error = salidas_deseadas[idx] - resultado
            if error != 0:
                cont_errores += 1
                # si hay error, ajustamos los pesos del perceptron
                for indice, x in enumerate(entrada):
                    pesos[indice] += x * error * taza_aprendizaje
                umbral += error * taza_aprendizaje

        if cont_errores == 0:
            # si no hay errores, salimos
            break

    print(f"Pesos finales: {pesos}\nUmbral: {umbral}")

    # probamos
    print(neurona((0, 0), pesos))
    print(neurona((0, 1), pesos))
    print(neurona((1, 0), pesos))
    print(neurona((1, 1), pesos))
