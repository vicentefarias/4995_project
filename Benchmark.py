import cv2
import time
import numpy as np
from Image import Image
from Video import Video

# read in the images
import time
import cv2


class PerformanceTest:
    def __init__(self, img):
        self.img = img
        self.image = Image(img=self.img)

    def image_alpha_blend_benchmark(self, iterations=100):
        total_time = 0
        for i in range(iterations):
            other_img = Image(img=self.img)
            other_weight = 50
            other_img.fit_to_size(self.image)
            start = time.time()
            self.image.alpha_blend(other_img, other_weight)
            end = time.time()
            total_time += (end - start)

        print('Alpha Blend (in ms): ' + str((total_time / iterations) * 1000))

    def image_edge_detection_benchmark(self, iterations=100):
        total_time = 0
        for i in range(iterations):
            start = time.time()
            cv2.Canny(self.img, 100, 200)
            end = time.time()
            total_time += (end - start)

        print('Image Edge Detection (in ms): ' + str((total_time / iterations) * 1000))

    def image_gaussian_blur_benchmark(self, iterations=100):
        total_time = 0
        for i in range(iterations):
            start = time.time()
            cv2.GaussianBlur(self.img, (15, 15), 0)
            end = time.time()
            total_time += (end - start)

        print('Image Gaussian Blur (in ms): ' + str((total_time / iterations) * 1000))

    def measure_homography_perspective(self, iterations=100):
        total_time = 0
        for i in range(iterations):
            pts = np.array([(0, 0), (0, 1), (1, 1), (1, 0)], dtype=np.float32)
            start = time.time()
            self.image.create_homography(pts)
            end = time.time()
            total_time += (end - start)

        print('Image Homography Perspective (in ms): ' + str((total_time / iterations) * 1000))

    def measure_getting_object_features(self, iterations=100):
        total_time = 0
        for i in range(iterations):
            start = time.time()
            self.image.get_object_features(self.img)
            end = time.time()
            total_time += (end - start)

        print('Image Gaussian Blur (in ms): ' + str((total_time / iterations) * 1000))

    def video_edge_detection_benchmark(self, iterations=1):
        total_time = 0
        for i in range(iterations):
            capture = cv2.VideoCapture("columbia_video.mp4")
            start = time.time()
            while True:
                ret, frame = capture.read()
                if not ret:
                    break
                edges = cv2.Canny(frame, 50, 100)
                cv2.imshow("Edge Detection", edges)

            end = time.time()
            total_time += (end - start)
        print('Video Edge Detection (in sec): ' + str((total_time / iterations)))

    def video_gaussian_blur_benchmark(self, iterations=1):
        total_time = 0
        for i in range(iterations):
            capture = cv2.VideoCapture("columbia_video.mp4")
            start = time.time()
            while True:
                ret, frame = capture.read()
                if not ret:
                    break
                cv2.GaussianBlur(frame, (15, 15), 0)

            end = time.time()
            total_time += (end - start)
        print('Video Gaussian Blur Detection (in sec): ' + str((total_time / iterations)))


    def video_alpha_blend_benchmark(self, iterations=1):
        total_time = 0
        for i in range(iterations):
            capture = cv2.VideoCapture("columbia_video.mp4")
            start = time.time()
            while True:
                ret, frame = capture.read()
                if not ret:
                    break
                other_img = Image(img=frame)
                other_weight = 50
                other_img.fit_to_size(self.image)
                self.image.alpha_blend(other_img, other_weight)
            end = time.time()
            total_time += (end - start)

        print('Video Alpha Blend (in sec): ' + str((total_time / iterations)))


img1 = cv2.imread("sp500.png")
test = PerformanceTest(img1)

test.image_alpha_blend_benchmark()
test.image_edge_detection_benchmark()
test.image_gaussian_blur_benchmark()

test.video_alpha_blend_benchmark()
test.video_edge_detection_benchmark()
test.video_gaussian_blur_benchmark()

# test.measure_homography_perspective()
# test.measure_getting_object_features()    DOES NOT WORK

