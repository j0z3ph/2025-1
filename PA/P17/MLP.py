import numpy as np


class MLP:
    """Clase Multi-Layer perceptron
    Implementacion de una red con una capa oculta de dos neuronas y una
    capa de salida con una neurona.
    Se esperan dos entradas, por lo que se deben aplicar dos pesos (uno por entrada) y
    un umbral de activacion a la primer neurona de entrada.
    Como la capa oculta es de dos neuronas, se requiere aplicar otros dos pesos
    a las entradas y el mismo umbral a la segunda neurona de entrada.
    
    Cada neurona de la capa oculta aplicara un peso a su salida, por lo que
    se necesitan dos pesos adicionales, para aplicarlos a las dos salidas 
    de las neuronas de la capa oculta, y un nuevo umbral para su activacion.
    
    Por lo tanto, se requieren seis pesos y dos umbrales. 4 pesos para la capa de entrada 
    y la capa oculta. 2 pesos para la capa oculta y la salida. 1 umbral para la entrada a la
    capa oculta. 1 umbral para capa oculta y la salida.
    
    Entrada1 - w1 -
                    > u1 - NeuronaOculta1 - w5 -
    Entrada2 - w2 -                              \
                                                    > u2 - Salida
    Entrada1 - w3 -                              /
                    > u1 - NeuronaOculta2 - w6 -
    Entrada2 - w4 -
    """

    def __init__(self) -> None:
        self.umbral1 = np.random.uniform(size=2)
        self.umbral2 = np.random.uniform()

        # self.umbral1 = np.zeros(2)
        # self.umbral2 = 0.

        self.perdidas = []

    def entrenar(
        self, datos_entrenamiento, salidas_esperadas, taza_aprendizaje=0.2, epochs=5000
    ):
        self.taza_aprendizaje = taza_aprendizaje
        self.datos_entrenamiento = datos_entrenamiento
        self.salidas_esperadas = salidas_esperadas
        self.epochs = epochs

        self.pesos12 = np.random.uniform(
            size=len(datos_entrenamiento[0])
        )  # Pesos de la neurona de entrada 1
        self.pesos34 = np.random.uniform(
            size=len(datos_entrenamiento[0])
        )  # Pesos de la neurona de entrada 2

        # self.pesos12 = np.zeros(2)
        # self.pesos34 = np.zeros(2)

        self.pesos56 = np.random.uniform(
            size=2
        )  # Pesos de las neuronas de la capa oculta (2 porque son 2 neuronas)

        # self.pesos56 = np.zeros(2)

        for epoch in range(self.epochs):
            self.propagacion_adelante(self.datos_entrenamiento)
            self.propagacion_atras()

            if epoch % 500 == 0:
                print(f"Epoch: {epoch} - Error: {self.perdidas[epoch]}")

    def propagacion_adelante(self, entradas):
        # Capa de entrada
        valorE1 = np.zeros(len(entradas))
        valorE2 = np.zeros(len(entradas))
        valorOculto = np.zeros(len(entradas))

        # Entrada 1 y 2
        for idx, entrada in enumerate(entradas):
            for id, x in enumerate(entrada):
                valorE1[idx] += x * self.pesos12[id]
                valorE2[idx] += x * self.pesos34[id]

            valorE1[idx] += self.umbral1[0]
            valorE2[idx] += self.umbral1[1]

        # Funcion de activacion de la capa de entrada
        res1 = self.activacion(valorE1)
        res2 = self.activacion(valorE2)

        self.salida_oculta = np.c_[res1, res2]

        # Capa oculta

        for idx, salida in enumerate(self.salida_oculta):
            for id, x in enumerate(salida):
                valorOculto[idx] += x * self.pesos56[id]
            valorOculto[idx] += self.umbral2

        self.salida_final = self.activacion(valorOculto)

        # print(self.salida_final)

        return self.salida_final

    def propagacion_atras(self):

        perdida = self.error(self.salidas_esperadas, self.salida_final)
        # print("perdida: ", perdida)
        self.perdidas.append(np.sum(perdida))

        error = self.salidas_esperadas - self.salida_final
        # print("error: ", error)

        p12 = np.zeros(2)
        p34 = np.zeros(2)
        p56 = np.zeros(2)
        umbral1 = np.zeros(2)
        umbral2 = 0.0

        # pesos
        for id, entrada in enumerate(self.datos_entrenamiento):
            for idx, x in enumerate(entrada):
                p12[idx] += (
                    self.gradiente(self.salida_final[id])
                    * self.pesos56[idx]
                    * self.gradiente(self.salida_oculta[id][idx])
                    * error[id]
                    * x
                )
                p34[idx] += (
                    self.gradiente(self.salida_final[id])
                    * self.pesos56[idx]
                    * self.gradiente(self.salida_oculta[id][idx])
                    * error[id]
                    * x
                )
                p56[idx] += (
                    self.gradiente(self.salida_final[id])
                    * error[id]
                    * self.salida_oculta[id][idx]
                )

        self.pesos12 += p12 * self.taza_aprendizaje
        self.pesos34 += p34 * self.taza_aprendizaje
        self.pesos56 += p56 * self.taza_aprendizaje

        # Umbrales
        for id, entrada in enumerate(self.datos_entrenamiento):
            for idx, x in enumerate(entrada):
                umbral1[idx] += (
                    self.gradiente(self.salida_final[id])
                    * self.pesos56[idx]
                    * self.gradiente(self.salida_oculta[id][idx])
                    * error[id]
                )
            umbral2 += self.gradiente(self.salida_final[id]) * error[id]

        self.umbral1 += umbral1 * self.taza_aprendizaje
        self.umbral2 += umbral2 * self.taza_aprendizaje

        # print("pesos1:", self.pesos12)
        # print("pesos2:", self.pesos34)
        # print("pesos3:", self.pesos56)
        # print("bias1: ", self.umbral1)
        # print("bias2: ", self.umbral2)

    def clasificar(self, entrada):
        return int(self.propagacion_adelante([entrada]) > 0.5)

    def activacion(self, valor):
        # Funcion sigmoide
        return 1 / (1 + np.exp(-valor))
        
    def gradiente(self, valor):
        # Derivada de la funcion sigmoide
        return valor * (1 - valor)

    def error(self, salida_deseada, resultado):
        # Error cuadratico medio
        return 0.5 * (salida_deseada - resultado) ** 2


if __name__ == "__main__":
    entradas = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    salidas = np.array([0, 1, 1, 0])

    nn = MLP()
    nn.entrenar(entradas, salidas, 0.2, 10001)

    print("Pesos finales: ", nn.pesos12, nn.pesos34, nn.pesos56)
    # probamos
    print(nn.clasificar([0, 0]))
    print(nn.clasificar([0, 1]))
    print(nn.clasificar([1, 0]))
    print(nn.clasificar([1, 1]))
