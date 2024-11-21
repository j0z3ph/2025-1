import cv2
import numpy as np

img = cv2.imread("amlove.jpg")
h,w,c = img.shape
kernel = np.array([[1/9,1/9,1/9],[1/9,1/9,1/9],[1/9,1/9,1/9]])

blur = np.zeros((h,w,c), np.uint8)

myk = kernel.shape[0]//2
mxk = kernel.shape[1]//2

for i in range(myk, h-myk):
    for j in range(mxk, w-mxk):
        sum=np.zeros(3)
        for ik in range(kernel.shape[0]):
            for jk in range(kernel.shape[1]):
                sum += kernel[ik,jk].astype('float')*img[i-myk+ik,j-mxk+jk].astype('float')
        blur[i,j] = sum

