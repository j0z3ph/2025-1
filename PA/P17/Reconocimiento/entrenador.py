import imutils
import cv2
import face_recognition
import pickle
import os

capture = cv2.VideoCapture(0)
trainedEncodings = []  # to store encodings
trainedIDs = []  # to store ids
cont = 0  # face image counter
MAXIMGS = 10  # maximum number of images to train
FACEDB = "facedatabase.dat"  # name of the database

file_dir = os.path.dirname(os.path.realpath(__file__))
FACEDB = os.path.join(file_dir, FACEDB)
FACEDB = os.path.abspath(os.path.realpath(FACEDB))

# Trying to read existing data
try:
    data = pickle.loads(open(FACEDB, "rb").read())
    trainedEncodings = data["encodings"]
    trainedIDs = data["ids"]
except Exception as inst:
    print(type(inst))
    print(inst.args)
    print(inst)

# print instructions
print("Entrenador\n")
userID = input("Escriba el ID del usuario: ")
print("A continuación, se abrira la cámara y se mostrará un recuadro verde. " +
      "Presione la tecla 'c' para entrenar el rostro.")
print("Se requieren " + str(MAXIMGS) +
      " imágenes en diversas posiciones.")

while (capture.isOpened()):
    ret, image = capture.read()
    rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # converts to RGB
    # performs face detection using HOG
    # optionally, cnn can be use instead of hog
    rects = face_recognition.face_locations(rgb, 0, "hog")

    # Press c to capture an image
    if (cv2.waitKey(1) == ord("c")):
        cont = cont + 1
        # compute the facial encodings for the face
        encodings = face_recognition.face_encodings(rgb, rects)
        for encoding in encodings:
            # add each encoding + id to our set of ids and encodings
            trainedEncodings.append(encoding)
            trainedIDs.append(userID)
        print("Muestra " + str(cont) + " capturada.")
    if (cont >= MAXIMGS):
        break

    # draw a green rectangle for each detected face
    for (x1, y1, x2, y2) in rects:
        cv2.rectangle(image, (y2, x1), (y1, x2), (0, 255, 0), 2)

    # print sample number on image
    image = cv2.putText(image, 'Muestra ' + str(cont + 1), (0, 20),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.5, (0, 0, 255), 2, cv2.LINE_AA)
    # show final image
    cv2.imshow('Entrenando...', image)

    # waits for 'ESC' key press (code 27)
    if (cv2.waitKey(1) == 27):
        break

# release the camera
capture.release()
cv2.destroyAllWindows()
# dump the facial encodings + ids to face database
print("Updating database...")
data = {"encodings": trainedEncodings, "ids": trainedIDs}
with open(FACEDB, 'wb') as fp:
    pickle.dump(data, fp)
print("Usuario '" + str(userID) + "' entrenado correctamente.")
