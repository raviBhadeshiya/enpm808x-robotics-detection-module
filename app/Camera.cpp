/**
 * @file Camera.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Camera.hpp>

Camera::Camera() {
  // cv::glob("../data/*.jpg",filenames_);
}

Camera::Camera(const std::string& filename) {
    filenames_.push_back(filename);
}

Camera::~Camera() {}
//
auto Camera::update() -> void {
  // TODO(raviBhadeshiya) : Camera update
}

auto Camera::getData() -> cv::Mat {
  // TODO(raviBhadeshiya) : Use video capture object here
  cv::Mat mat;
  return mat;
}

auto Camera::isOpened() -> bool {
    if(!imgSeq_) return video_capture_.isOpened();
    return !filenames_.empty();}

auto Camera::getFilenames() -> std::vector<cv::String> { return filenames_; }

#ifdef CAMERA_TEST
auto Camera::test() -> void {
}
#endif
