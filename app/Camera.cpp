/**
 * @file Camera.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Camera.hpp>

// Default constructor
Camera::Camera() {
  // cv::glob("../data/*.jpg",filenames_);
}

// Overloaded constructor to read files
Camera::Camera(const std::string& filename) {
  // Find the extension of file
  auto idx = filename.rfind('.');
  if (idx != std::string::npos) {
    // if it is video file
    if (filename.substr(idx + 1) == "mp4" ||
        filename.substr(idx + 1) == "avi") {
      this->imgSeq_ = false;
      // Update video capture object
      this->video_capture_ = cv::VideoCapture(filename);
    } else if (filename.substr(idx + 1) == "jpg" ||
               filename.substr(idx + 1) == "png") {
      // If it is not video file than read all images in that folder
      this->imgSeq_ = true;
      cv::glob(filename, this->filenames_);
    }
  } else {
    // If invalid file than exit wiith error
    std::cerr << "Invaid Filename!" << std::endl;
    exit(-2);
  }
}

// Default constructor
Camera::~Camera() {}

// Camera update will read each frame/file
auto Camera::update() -> void {
  // check for last condition and provide empty file
  if (!this->isOpened()) this->data_ = cv::imread("null.jpg");
  // if its is video than
  if (!this->imgSeq_) {
    this->video_capture_ >> this->data_;
  } else {
    // read imgae from vector and pop for next image
    if (!this->filenames_.empty()) {
      auto i = this->filenames_.back();
      this->filenames_.pop_back();
      // read image
      this->data_ = cv::imread(i);
    }
  }
}

// GetData update the next image and return updated image
auto Camera::getData()->cv::Mat {
    this->update();
    return this->data_;
}

// check for end condition of video or image seqaunce
auto Camera::isOpened() -> bool {
    if (!this->imgSeq_) return this->video_capture_.isOpened();
    return !this->filenames_.empty();
}

// Return images filename in vector
auto Camera::getFilenames() -> std::vector<cv::String> {
    return this->filenames_;
}

// For testing camera but first toggele the comment in header
#ifdef CAMERA_TEST
auto Camera::test() -> void {
  if (!this->isOpened()) {
    std::cout << "Error opening video stream or image file" << std::endl;
    return;
  }
  cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);
  while (true) {
    cv::Mat frame = this->getData();
    if (frame.empty()) break;
    cv::imshow("Display Window", frame);
    if (cv::waitKey(30) >= 0) break;
  }
  cv::waitKey(0);
}
#endif
