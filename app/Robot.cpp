/**
 * @file Robot.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <memory>
#include <string>
#include "Robot.hpp"

// Create robot object
Robot::Robot() { isSetup_ = false; }

// Destroy robot object
Robot::~Robot() {}

// Setup as preprocessor macro
auto Robot::setup() -> void {
  detector_ = std::make_unique<Detection>(
      "../data/MobileNetSSD_deploy.prototxt",
      "../data/MobileNetSSD_deploy.caffemodel");  // Load neural net

  camera_ = std::make_unique<Camera>();  // Default Camera
  isSetup_ = false;
}
// Setup as preprocessor macro
auto Robot::setup(const std::string& arg) -> void {
  detector_ = std::make_unique<Detection>(
      "../data/MobileNetSSD_deploy.prototxt",
      "../data/MobileNetSSD_deploy.caffemodel");  // Load neural net

  camera_ = std::make_unique<Camera>(
      arg);  // Camera will provide video frame or image sequence
  isSetup_ = true;
}

#ifdef CAMERA_ENABLE
// Setup as preprocessor macro
auto Robot::setup(const int& deviceId) -> void {
  detector_ = std::make_unique<Detection>(
      "../data/MobileNetSSD_deploy.prototxt",
      "../data/MobileNetSSD_deploy.caffemodel");  // Load neural net

  camera_ = std::make_unique<Camera>(
      deviceId);  // Camera will provide video frame or image sequence
  isSetup_ = true;
}
#endif

// Update method for detection and display demo
auto Robot::update(bool display) -> void {
  if (!isSetup_) return;

  if (display) cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);

  cv::Mat frame;

  int counter = 0;

  for (;;) {
    frame = this->camera_->getData();   // Provide frame or images as init

    if (frame.empty())
      break;   // if end condition then break

    // cv::TickMeter tm;
    // tm.start();

    frame = this->detector_->update(frame);

    // tm.stop();
    // std::cout << "Inference time, ms: " << tm.getTimeMilli() << std::endl;
    // Detect the objects

    if (this->camera_->isImageSeq()) {
      // Store each image in output folder
      std::stringstream file;
      file << "../output/result" << counter << ".jpg";
      cv::imwrite(file.str(), frame);
    }

    counter++;  // increment counter

    if (display) cv::imshow("Display Window", frame);
    // Showing image

    if (display) if (cv::waitKey(30) >= 0) break;   // Esc for break
  }
  std::cout << "Press ESC for exit.." << std::endl;
  if (display) cv::waitKey(0);
  // wait for ESC press
}
