import cv2
vid = cv2.VideoCapture(0)
if not vid.isOpened():
    print("Cannot open camera")
    exit()
while(True):
	ret, frame = vid.read()
	cv2.imshow('Camara', frame)
	if cv2.waitKey(1) == ord('q'):
		break

vid.release()
cv2.destroyAllWindows()
