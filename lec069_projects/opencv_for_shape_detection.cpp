#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Function to detect and label shapes
void detectShapes(const Mat &inputImage) {
    Mat grayImage, blurredImage, cannyOutput;

    // Convert the image to grayscale
    cvtColor(inputImage, grayImage, COLOR_BGR2GRAY);

    // Blur the image slightly to reduce noise
    GaussianBlur(grayImage, blurredImage, Size(5, 5), 0);

    // Detect edges using Canny
    Canny(blurredImage, cannyOutput, 50, 150);

    // Find contours in the edge-detected image
    vector<vector<Point>> contours;
    findContours(cannyOutput, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Iterate over each contour
    for (const auto &contour : contours) {
        // Approximate the contour with a polygon
        vector<Point> approx;
        approxPolyDP(contour, approx, 0.02 * arcLength(contour, true), true);

        // Get the number of vertices in the polygon
        int vertices = approx.size();

        // Calculate the bounding box of the contour
        Rect boundingBox = boundingRect(approx);

        // Label the shape based on the number of vertices
        string shape;
        if (vertices == 3) {
            shape = "Triangle";
        } else if (vertices == 4) {
            // Check if the shape is a square or rectangle
            double aspectRatio = (double)boundingBox.width / boundingBox.height;
            if (aspectRatio >= 0.95 && aspectRatio <= 1.05)
                shape = "Square";
            else
                shape = "Rectangle";
        } else if (vertices > 4) {
            // Check for circular shapes using contour area and perimeter
            double area = contourArea(contour);
            double perimeter = arcLength(contour, true);
            double circularity = 4 * CV_PI * (area / (perimeter * perimeter));
            if (circularity > 0.8)
                shape = "Circle";
            else
                shape = "Polygon";
        }

        // Draw the contour and shape name on the original image
        drawContours(inputImage, vector<vector<Point>>{approx}, -1, Scalar(0, 255, 0), 2);
        putText(inputImage, shape, Point(boundingBox.x, boundingBox.y - 10),
                FONT_HERSHEY_SIMPLEX, 0.6, Scalar(255, 0, 0), 2);
    }

    // Show the result
    imshow("Shape Detection", inputImage);
}

int main() {
    // Load an image from file
    Mat image = imread("shapes.png");

    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // Detect and label shapes
    detectShapes(image);

    // Wait until a key is pressed
    waitKey(0);
    return 0;
}
