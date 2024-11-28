import cv2
import numpy as np

img = cv2.imread("test.png")

#cv2.MORPH_CROSS
#cv2.MORPH_RECT
#cv2.MORPH_ELLIPSE

kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (7,7))
#print(kernel)

res = cv2.erode(img, kernel)

cv2.imshow("test", img)
cv2.imshow("Erocion", res)
cv2.waitKey()