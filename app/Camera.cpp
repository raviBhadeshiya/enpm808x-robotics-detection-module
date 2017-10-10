/**
 * @file Camera.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Camera.hpp>

Camera::Camera() {
    video_capture_ = cv::VideoCapture(0);
}

Camera::Camera(const int id) {
    video_capture_ = cv::VideoCapture(id);
}

Camera::~Camera() {}

auto Camera::update() -> void {
    // TODO(raviBhadeshiya) : Camera update
}

auto Camera::getData() -> cv::Mat {
    cv::Mat Image;
    // TODO(raviBhadeshiya) : Use video capture object here
    return Image;
}

auto Camera::isRunning() -> bool {
    return isRunning_;
}
