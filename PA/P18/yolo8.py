import datetime
from ultralytics import YOLO
import cv2

CONFIDENCE_THRESHOLD = 0.9
GREEN = (0, 255, 0)

video_cap = cv2.VideoCapture(0)

model = YOLO("dr.strange.pt")
#model = YOLO("yolov8n.pt")
#model = YOLO("best.pt")
names = model.names

while True:
    start = datetime.datetime.now()
    ret, frame = video_cap.read()

    if not ret:
        break

    # run the YOLO model on the frame
    detections = model(frame, verbose=False)[0]

    # loop over the detections
    for data in detections.boxes.data.tolist():
        # data[0]: x1
        # data[1]: y1
        # data[2]: x2
        # data[3]: y2
        # data[4]: score
        # data[5]: label index

        # extract the confidence (i.e., probability) associated with the detection
        confidence = data[4]

        # filter out weak detections by ensuring the
        # confidence is greater than the minimum confidence
        if float(confidence) < CONFIDENCE_THRESHOLD:
            continue

        # if the confidence is greater than the minimum confidence,
        # draw the bounding box on the frame
        xmin, ymin, xmax, ymax = int(data[0]), int(data[1]), int(data[2]), int(data[3])
        label = names[int(data[5])]
        cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), GREEN, 5)
        # draw class name
        cv2.putText(
            frame, label, (xmin, ymin - 10), cv2.FONT_HERSHEY_SIMPLEX, 1, GREEN, 2
        )

        # end time to compute the fps
    end = datetime.datetime.now()
    # show the time it took to process 1 frame
    total = (end - start).total_seconds()

    # calculate the frame per second and draw it on the frame
    fps = f"FPS: {1 / total:.2f}"
    cv2.putText(frame, fps, (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 0, 255), 8)

    # show the frame to our screen
    cv2.imshow("Frame", frame)
    if cv2.waitKey(1) == 27:
        break

video_cap.release()
cv2.destroyAllWindows()
