import cv2
img_gs = cv2.imread('im2.jpg', 0)
processed_image = cv2.medianBlur(img_gs, 7)
cv2.imshow('im2.jpg', img_gs)
cv2.imshow('Median Filter Processing', processed_image)
cv2.imwrite('processed_image.png', processed_image)
cv2.waitKey(0)