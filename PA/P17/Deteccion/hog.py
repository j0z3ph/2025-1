import dlib
import cv2

capture = cv2.VideoCapture(0)
# load dlib's HOG + Linear SVM face detector
detector = dlib.get_frontal_face_detector()

while capture.isOpened():
    ret, image = capture.read()
    rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # perform face detection using dlib's face detector
    # the second argument is the scale factor. 0 means no scale.
    rects = detector(rgb, 0)

    for rect in rects:
        cv2.rectangle(image,(rect.left(), rect.top()),(rect.right(), rect.bottom()),
            (0, 255, 0),2)

    cv2.imshow("Caras", image)
    if cv2.waitKey(1) == 27:
        break

capture.release()
cv2.destroyAllWindows()
