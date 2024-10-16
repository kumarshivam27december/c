#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load the image
    Mat image = imread("coins.jpg");

    // Check if the image was loaded successfully
    if (image.empty()) {
        cout << "Error loading image" << endl;
        return -1;
    }

    // Convert the image to grayscale for better processing
    cvtColor(image, image, COLOR_BGR2GRAY);

    // Apply Gaussian blur to reduce noise
    GaussianBlur(image, image, Size(5, 5), 0);

    // Apply thresholding to create a binary image
    threshold(image, image, 127, 255, THRESH_BINARY);

    // Find contours in the binary image
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Filter contours based on area and circularity to identify coins
    vector<vector<Point>> coins;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        double perimeter = arcLength(contours[i], true);
        double circularity = 4 * CV_PI * area / (perimeter * perimeter);

        // Set thresholds for area and circularity based on your coin characteristics
        if (area > 1000 && circularity > 0.7) {
            coins.push_back(contours[i]);
        }
    }

    // Draw circles around detected coins
    for (size_t i = 0; i < coins.size(); i++) {
        circle(image, minEnclosingCircle(coins[i]).center, minEnclosingCircle(coins[i]).radius, Scalar(0, 255, 0), 2);
    }

    // Display the result
    imshow("Detected Coins", image);
    waitKey(0);

    return 0;
}
