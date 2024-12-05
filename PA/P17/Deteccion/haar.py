import cv2
import os

capture = cv2.VideoCapture(0)
file_dir = os.path.dirname(os.path.realpath(__file__))
# load haar cascade
haarCascade = 'haarcascade_frontalface_default.xml'  
haarCascade = os.path.join(file_dir, haarCascade)
haarCascade = os.path.abspath(os.path.realpath(haarCascade))
# creates cascade classifier
face_cascade = cv2.CascadeClassifier(haarCascade)

while (capture.isOpened()):
    ret, image = capture.read()
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # detect face using haar cascades
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    for (x,y,w,h) in faces:
        cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)

    cv2.imshow('Caras', image)
    if (cv2.waitKey(1) == 27):
        break

capture.release()
cv2.destroyAllWindows()
