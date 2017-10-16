/**
 * @file Detection.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include "Detection.hpp"

Detection::Detection() : Module() {
  this->isSetup_ = false;
}

Detection::Detection(const cv::String& modelConfig, const cv::String& binary): Module() {
  this->modelConfiguration_ = modelConfig;
  this->modelBinary_ = binary;
  this->isSetup_ = true;
  this->import();
}

Detection::~Detection() {}

auto Detection::import() -> void {
  // modelConfiguration_ = "../data/MobileNetSSD_deploy.prototxt";
  // modelBinary_ = "../data/MobileNetSSD_deploy.caffemodel";
}

// Update evrything for detection
auto Detection::update(const cv::Mat& frame) -> cv::Mat {
  cv::Mat detectionMat;
  return render(frame, detectionMat);
}

// Overloaded update method for internal file
auto Detection::update() -> void {
  if (!this->frame_.empty()) this->frame_ = update(this->frame_);
}

auto Detection::getObjects(const cv::Mat& frame) -> cv::Mat {
  // TODO(raviBhadeshiya) : method to find object detection
  return frame;
}

auto Detection::preProcess(const cv::Mat& frame) -> cv::Mat {
  // TODO(raviBhadeshiya) : preProcess the Image for better detection
  cv::Mat preProcessed;
  return preProcessed;
}

auto Detection::getMean(const int& width, const int& height) -> cv::Mat {
  cv::Mat mean;
  return mean;
}

auto Detection::render(const cv::Mat& frame, const cv::Mat& detectionMat)
    -> cv::Mat {
  // TODO(raviBhadeshiya) : render boundary of object in image
  return frame;
}

auto Detection::isSetup(void) -> bool { return isSetup_; }
