import cv2
import numpy as np

# Create a blank white image
img = np.ones((400, 600, 3), dtype=np.uint8) * 255

# Draw some circles (center_x, center_y), radius, color (BGR), thickness
cv2.circle(img, (100, 100), 50, (0, 0, 255), 3)      # Red circle
cv2.circle(img, (300, 100), 30, (0, 255, 0), -1)     # Filled green circle

# Draw some ellipses
cv2.ellipse(img, (200, 300), (80, 40), 0, 0, 360, (255, 0, 0), 4)       # Blue ellipse
cv2.ellipse(img, (400, 300), (60, 30), 45, 0, 270, (0, 255, 255), 5)    # Yellow partial ellipse

# Save image to file
cv2.imwrite('generated_shapes.png', img)

# Show the image (optional)
cv2.imshow('Circles and Ellipses', img)
cv2.waitKey(0)
cv2.destroyAllWindows()