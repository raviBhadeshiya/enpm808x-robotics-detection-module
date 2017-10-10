/**
 * @file Detection.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Detection.hpp>

Detection::Detection():Module() {
    isSetup_ = false;
}

Detection::~Detection() {}

auto Detection::update() -> void {
    // TODO(raviBhadeshiya) : update method
}

auto Detection::getObjects(cv::Mat frame) -> cv::Mat {
    // TODO(raviBhadeshiya) : method to find object using Harr cascade
    return frame;
}

auto Detection::preProcess(cv::Mat frame) -> cv::Mat {
    // TODO(raviBhadeshiya) : preProcess the Image for better detection
    return frame;
}

auto Detection::render(cv::Mat frame) -> cv::Mat {
    // TODO(raviBhadeshiya) : render boundary of object in image
    return frame;
}

auto Detection::isSetup(void) -> bool {
    return isSetup_;
}
