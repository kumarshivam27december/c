#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_video> <output_video>" << std::endl;
        return -1;
    }

    // Input and output video file names
    std::string inputVideoFile = argv[1];
    std::string outputVideoFile = argv[2];

    // Open the input video
    cv::VideoCapture cap(inputVideoFile);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the input video file." << std::endl;
        return -1;
    }

    // Get video properties
    int frameWidth = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeight = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));

    // Define the codec and create VideoWriter object
    cv::VideoWriter out(outputVideoFile, cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, cv::Size(frameWidth, frameHeight));

    if (!out.isOpened()) {
        std::cerr << "Error: Could not open the output video file for writing." << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // Capture frame-by-frame
        cap >> frame;
        if (frame.empty()) break; // Check for end of video

        // Apply Gaussian blur
        cv::Mat blurredFrame;
        cv::GaussianBlur(frame, blurredFrame, cv::Size(15, 15), 0);

        // Write the blurred frame to the output video
        out << blurredFrame;
    }

    // Release resources
    cap.release();
    out.release();

    std::cout << "Video processing completed. Blurred video saved to " << outputVideoFile << std::endl;

    return 0;
}
