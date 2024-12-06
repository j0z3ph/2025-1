import cv2
import face_recognition
import pickle
import os

capture = cv2.VideoCapture(0)
FACEDB = "facedatabase.dat"  # name of the database

file_dir = os.path.dirname(os.path.realpath(__file__))
FACEDB = os.path.join(file_dir, FACEDB)
FACEDB = os.path.abspath(os.path.realpath(FACEDB))

# confidence 
conf = 0.7 # percent of images needed to get a match 
maxImgs = 10 # Max number of images trained per person

# load the faces database
print("Loading database...")
faceData = pickle.loads(open(FACEDB, "rb").read())

while (capture.isOpened()):
    ret, image = capture.read()
    rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    # detect face using HOG
    # optionally, cnn can be use instead of hog
    rects = face_recognition.face_locations(rgb, 0, "hog")
    # get encodings of detected faces
    encodings = face_recognition.face_encodings(rgb, rects)
    userIDs = []
    # loop over the encodings
    for encoding in encodings:
        # attempt to match each face in the input image to our known
        # encodings
        matches = face_recognition.compare_faces(faceData["encodings"],
                                                 encoding, 0.6)
        # matches contains a list of True/False values indicating
        # which known_face_encodings match the face encoding to check
        id = "Unknown"
        # check to see if we have found a match i.e. we have at least
        # one True value in matches
        if True in matches:
            matchedIdxs = []
            # find the indexes of all matched faces then initialize a
            # dictionary to count the total number of times each face
            # was matched
            for (idx, value) in enumerate(matches):
                if value:
                    matchedIdxs.append(idx)
            
            counts = {}
            # loop over the matched indexes and maintain a count for
            # each recognized face
            for i in matchedIdxs:
                id = faceData["ids"][i]
                counts[id] = counts.get(id, 0) + 1
            # determine the recognized face with the largest number of votes
            id = max(counts, key=counts.get)
            print(counts)
            if(counts[id] < (maxImgs * conf)):
                id = "Unknown"

        # update the list of ids
        userIDs.append(id)

    # loop over the recognized faces
    for ((x1, y1, x2, y2), id) in zip(rects, userIDs):
        # draw the predicted face id on the image
        cv2.rectangle(image, (y2, x1), (y1, x2), (0, 255, 0), 2)
        y = x1 - 15 if x1 - 15 > 15 else x1 + 15
        cv2.putText(image, id, (y2, y), cv2.FONT_HERSHEY_SIMPLEX,
                    0.75, (0, 255, 0), 2)

    cv2.imshow('Reconocedor', image)
    if (cv2.waitKey(1) == 27):
        break

capture.release()
cv2.destroyAllWindows()
