import dlib
import cv2
import os

capture = cv2.VideoCapture(0)
# load dlib's CNN face detector
model = "mmod_human_face_detector.dat"  # model file name

file_dir = os.path.dirname(os.path.realpath(__file__))
model = os.path.join(file_dir, model)
model = os.path.abspath(os.path.realpath(model))

detector = dlib.cnn_face_detection_model_v1(model)

while (capture.isOpened()):
    ret, image = capture.read()
    rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # perform face detection using dlib's face detector
    # the second argument is the scale factor. 0 means no scale.
    rects = detector(rgb, 0)

    for r in rects:
        cv2.rectangle(image, (r.rect.left(), r.rect.top()),
                      (r.rect.right(), r.rect.bottom()), (0, 255, 0), 2)

    cv2.imshow('Caras', image)
    if (cv2.waitKey(1) == 27):
        break

capture.release()
cv2.destroyAllWindows()
