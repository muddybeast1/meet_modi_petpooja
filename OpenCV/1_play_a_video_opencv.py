import cv2
cap = cv2.VideoCapture(0)

if cap.isOpened() == False:
    print("Could not open external camera.")
else:
    while True:
        ret, frame = cap.read()
        if ret:
            cv2.imshow("External Cam", frame)
        else:
            print("Can't receive frame. Exiting...")
            break

        if cv2.waitKey(1) == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()
