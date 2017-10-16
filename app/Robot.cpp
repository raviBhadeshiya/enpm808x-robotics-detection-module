/**
 * @file Robot.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Robot.hpp>

// Create robot object
Robot::Robot() {}

// Destroy robot object
Robot::~Robot() {}

// Setup as preprocessor macro
auto Robot::setup() -> void {
  detector_ = std::make_unique<Detection>(
      "../data/MobileNetSSD_deploy.prototxt",
      "../data/MobileNetSSD_deploy.caffemodel");  // Load neural net

#ifdef IMAGE_SEQUENCE
  camera_ = std::make_unique<Camera>(
      "../data/*.jpg");  // Camera will provide image sequence
#else
  camera_ = std::make_unique<Camera>(
      "../data/test.mp4");  // Camera will provide video frame
#endif
}

// Update method for detection and display demo
auto Robot::update() -> void {
  cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);
  cv::Mat frame;

#ifdef IMAGE_SEQUENCE
  int counter = 0;  // if image sequence init counter
#endif

  for (;;) {
    frame = this->camera_->getData();  // Provide frame or images as init

    if (frame.empty()) break;  // if end condition then break

    frame = this->detector_->update(frame);  // Detect the objects

#ifdef IMAGE_SEQUENCE
    // Store each image in output folder
    std::stringstream file;
    file << "../output/result" << counter << ".jpg";
    cv::imwrite(file.str(), frame);
    counter++;  // increment counter
#endif

    cv::imshow("Display Window", frame);  // Showing image

    if (cv::waitKey(30) >= 0) break;  // Esc for break
  }
  std::cout << "Press ESC for exit.." << std::endl;

  cv::waitKey(0);  // wait for ESC press
}
