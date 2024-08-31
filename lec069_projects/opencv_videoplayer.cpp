#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <video_file>" << std::endl;
        return -1;
    }

    // Open the video file
    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open the video file." << std::endl;
        return -1;
    }

    // Get the video frame width and height
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));

    // Create a window to display the video
    cv::namedWindow("Video Playback", cv::WINDOW_AUTOSIZE);

    cv::Mat frame;
    while (true) {
        // Read a frame from the video file
        cap >> frame;

        // Check if the frame is empty (end of video)
        if (frame.empty()) {
            break;
        }

        // Display the frame
        cv::imshow("Video Playback", frame);

        // Wait for 30 milliseconds and check for 'q' key press to exit
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }

    // Release the video capture object and destroy all windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
