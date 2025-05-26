import cv2
import numpy as np

# Load image
img = cv2.imread('generated_shapes.png')
if img is None:
    print("Could not read image")
    exit()

output = img.copy()
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(gray, (7, 7), 2)

# --- Detect Circles ---
circles = cv2.HoughCircles(blur, cv2.HOUGH_GRADIENT, dp=1.2, minDist=30,
                           param1=50, param2=30, minRadius=10, maxRadius=0)

if circles is not None:
    circles = np.uint16(np.around(circles))
    for i in circles[0, :]:
        # Draw the outer circle
        cv2.circle(output, (i[0], i[1]), i[2], (0, 255, 0), 2)
        # Draw the center of the circle
        cv2.circle(output, (i[0], i[1]), 2, (0, 0, 255), 3)

# --- Detect Ellipses ---
# Find edges and contours
edges = cv2.Canny(blur, 50, 150)
contours, _ = cv2.findContours(edges, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)

for cnt in contours:
    if len(cnt) >= 5:  # fitEllipse needs at least 5 points
        ellipse = cv2.fitEllipse(cnt)
        # Filter by ellipse size or shape if needed here
        cv2.ellipse(output, ellipse, (255, 0, 0), 2)

# Show result
cv2.imshow('Circles and Ellipses', output)
cv2.waitKey(0)
cv2.destroyAllWindows()
