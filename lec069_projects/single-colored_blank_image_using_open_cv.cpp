#include <opencv2/opencv.hpp>

int main() {
    // Define the image dimensions
    int width = 800;
    int height = 600;

    // Define the color (BGR format)
    cv::Scalar color(0, 255, 0); // Green

    // Create the image with the specified dimensions and color
    cv::Mat image(height, width, CV_8UC3, color);

    // Save the image to a file
    cv::imwrite("single_colored_image.png", image);

    // Optionally display the image
    cv::namedWindow("Single Colored Image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Single Colored Image", image);
    cv::waitKey(0); // Wait for a key press before closing

    return 0;
}
