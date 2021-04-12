import numpy as np
import cv2

img = cv2.imread('im1.jpg')
grayscale = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# edge_kernel = np.array([[-1,-1,-1], [-1,9,-1], [-1,-1,-1]])
sharpen_kernel = np.array([[0,-1,0],
                           [-1,5,-1],
                           [0,-1,0]])
imgs = cv2.filter2D(grayscale, -1, sharpen_kernel)

# Smooth out image
# blur = cv2.medianBlur(img, 3)
blur = cv2.GaussianBlur(imgs, (3,3), 0)


cv2.imshow('imgs',imgs)
cv2.imshow('grayscale',grayscale)
cv2.imwrite('img.png',imgs)
cv2.imshow('blur',blur)
cv2.imwrite('blur.png',blur)
cv2.waitKey(0)