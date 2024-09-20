#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the image
    cv::Mat image = cv::imread("input.jpg");

    // Check if the image is loaded successfully
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Create a matrix to store the output (blurred) image
    cv::Mat blurredImage;

    // Apply Gaussian blur
    int kernelSize = 15; // Change this value for different blur intensity
    cv::GaussianBlur(image, blurredImage, cv::Size(kernelSize, kernelSize), 0);

    // Save the blurred image
    cv::imwrite("blurred_output.jpg", blurredImage);

    // Display original and blurred images
    cv::imshow("Original Image", image);
    cv::imshow("Blurred Image", blurredImage);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    return 0;
}
