import numpy as np


class Perceptron:

    def __init__(self) -> None:
        self.umbral = -0.5

    def entrenar(
        self,
        datos_entrenamiento,
        salidas_esperadas,
        taza_aprendizaje=0.1
    ):
        self.taza_aprendizaje = taza_aprendizaje
        self.datos_entrenamiento = datos_entrenamiento
        self.salidas_esperadas = salidas_esperadas
        self.pesos = np.zeros(len(datos_entrenamiento[0]))
        
        while True:
            cont_errores = 0

            for idx, entrada in enumerate(self.datos_entrenamiento):
                resultado = self.clasificar(entrada)
                error = self.error(self.salidas_esperadas[idx], resultado)
                if error != 0:
                    cont_errores += 1
                    # si hay error, ajustamos los pesos del perceptron
                    self.actualiza_pesos(entrada, error)

            if cont_errores == 0:
                # si no hay errores, salimos
                break

        print(f"Pesos finales: {self.pesos}")

    def clasificar(self, entrada):
        # multiplicamos cada entrada por su respectivo peso y los sumamos
        valor = 0
        # producto punto
        for idx, x in enumerate(entrada):
            valor += x * self.pesos[idx]

        # sumamos el umbral
        valor += self.umbral
        # devolvemos 1 si la neurona se activa, 0 si no se activa
        return self.activacion(valor)

    def activacion(self, valor):
        return int(valor >= 0)

    def error(self, salida_deseada, resultado):
        return salida_deseada - resultado

    def actualiza_pesos(self, entrada, error):
        # actualizamos cada peso sumando el valor de la entrada por el error y la taza de aprendizaje
        # si no hay error (error = 0), el peso no se modifica
        # si hay error (error != 0), al peso se le suma el producto de la entrada por el error por la
        # taza de aprendizaje
        for indice, x in enumerate(entrada):
            self.pesos[indice] += x * error * self.taza_aprendizaje
        # actualizamos el umbral considerando el valor de la entrada como 1
        self.umbral += error * self.taza_aprendizaje
