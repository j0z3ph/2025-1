from perceptron import Perceptron

if __name__ == "__main__":

    entradas = [(0, 0), (0, 1), (1, 0), (1, 1)]
    salidas_deseadas = [0, 0, 0, 1]

    neurona = Perceptron()
    neurona.entrenar(entradas, salidas_deseadas)

    print(neurona.clasificar((0, 0)))
    print(neurona.clasificar((0, 1)))
    print(neurona.clasificar((1, 0)))
    print(neurona.clasificar((1, 1)))