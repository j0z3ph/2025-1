"""
Perceptron entrenado para ser XOR 
Se usan los pesos de los perceptrones AND, OR y NOT
A XOR B = (A AND NOT B) OR (NOT A AND B) = OR(AND(A, NOT(B)), AND(NOT(A), B))
"""

from perceptron import Perceptron

def red_neuronal_XOR(entrada):
    # OR(AND(A, NOT(B)), AND(NOT(A), B))
    nA = neurona_not.clasificar([entrada[0]])  # NOT A
    nB = neurona_not.clasificar([entrada[1]])  # NOT B
    andAnB = neurona_and.clasificar((entrada[0], nB))  # AND(A, NOT(B))
    andnAB = neurona_and.clasificar((nA, entrada[1]))  # AND(NOT(A), B)
    xor = neurona_or.clasificar((andAnB, andnAB))  # OR(AND(A, NOT(B)), AND(NOT(A), B))
    return xor

def red_neuronal_XNOR(entrada):
    xor = red_neuronal_XOR(entrada)
    return neurona_not.clasificar([xor]) # NOT(XOR)


if __name__ == "__main__":
    entradas = [(0, 0), (0, 1), (1, 0), (1, 1)]
    salidas = [[0, 0, 0, 1], [0, 1, 1, 1], [1, 0]]

    neurona_and = Perceptron()
    neurona_or = Perceptron()
    neurona_not = Perceptron()

    neurona_and.entrenar(entradas, salidas[0])
    neurona_or.entrenar(entradas, salidas[1])
    neurona_not.entrenar([[0], [1]], salidas[2])
    
    # probamos
    print(red_neuronal_XOR((0, 0)))
    print(red_neuronal_XOR((0, 1)))
    print(red_neuronal_XOR((1, 0)))
    print(red_neuronal_XOR((1, 1)))
    
    print(red_neuronal_XNOR((0, 0)))
    print(red_neuronal_XNOR((0, 1)))
    print(red_neuronal_XNOR((1, 0)))
    print(red_neuronal_XNOR((1, 1)))
