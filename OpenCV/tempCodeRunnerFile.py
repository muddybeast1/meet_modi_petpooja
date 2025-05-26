# Use external camera (usually index 1, try 2 or 3 if needed)
# cap = cv2.VideoCapture(1)

# if cap.isOpened() == False:
#     print("Could not open external camera.")
# else:
#     while True:
#         ret, frame = cap.read()
#         if ret:
#             cv2.imshow("External Cam", frame)
#         else:
#             print("Can't receive frame. Exiting...")
#             break

#         if cv2.waitKey(1) == ord('q'):
#             break

#     cap.release()
#     cv2.destroyAllWindows()
