import cv2
import numpy as np

amlo = cv2.imread('amlove.jpg')
#evilamlo = np.clip((255-amlo), 0, 255).astype('uint8')
h,w,c = amlo.shape
masamlo = np.zeros((h,w,c), np.uint8)

CONSTANTE=-50
for fila in range(h):
    for columna in range(w):
        masamlo[fila,columna] =np.clip(amlo[fila,columna].astype('uint16') + CONSTANTE, 0, 255).astype('uint8')

cv2.imshow("AMLO Solito", amlo)

cv2.imshow("Mas AMLO", masamlo)

#cv2.imshow('Evil Amlove', evilamlo)
cv2.waitKey()
