import cv2
import numpy as np

img = cv2.imread("Papucho.jpg")
h, w, c = img.shape
print(h,w,c)
gris = np.zeros((h,w),np.uint8)

for i in range(h):
    for j in range(w):
        prom = np.clip((img[i,j,0].astype('uint') + img[i,j,1].astype('uint') + img[i,j,2].astype('uint'))/3,0,255)
        gris[i,j] = prom
        
cv2.imshow("Papucho", img)
cv2.imshow("Papucho Gris", gris)
cv2.waitKey()