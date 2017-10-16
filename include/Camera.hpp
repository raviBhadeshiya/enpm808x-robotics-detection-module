/**
 * @file Camera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 *
 * @brief Camera Module
 *
 * @section DESCRIPTION
 * This camera module will provide the images for detection
 * by reading jpg/png images or reading a video files.
 *
 */
#pragma once
#include <opencv2/opencv.hpp>
#include <memory>
#include <string>
#include <vector>
#include "Sensor.hpp"
// #define CAMERA_TEST // Toggle comment as per requirements

/**
 * @brief      Class for camera inherited from sensor.
 */
class Camera : public Sensor<cv::Mat> {
 public:
  /**
   * @brief      Create the camera object.
   */
  Camera();
  /**
   * @brief      Create specific the camera object as per file name.
   *
   * @param[in]  id    The device identifier.
   */
  explicit Camera(const std::string& file);
  /**
   * @brief      Destroys the object.
   */
  ~Camera();
  /**
 * @brief      Update method.
 *
 * @return     return none.
 */
  auto update() -> void;
  /**
   * @brief      Determines if Camera running.
   *
   * @return     True if Camera running, False otherwise.
   */
  auto isOpened() -> bool;
  /**
   * @brief      Gets the data.
   *
   * @return     The data.
   */
  auto getData() -> cv::Mat;
  /**
   * @brief      Gets the filenames.
   *
   * @return     The filenames.
   */
  auto getFilenames() -> std::vector<cv::String>;

#ifdef CAMERA_TEST
  /**
   * @brief      Test fucntion for checking
   *
   * @return     return none
   */
  auto test() -> void;
#endif

 private:
  /**
   * @brief      video_capture_ as opencv video capture object
   */
  cv::VideoCapture video_capture_;
  /**
   * @brief      Image as cv matric
   */
  cv::Mat data_;
  /**
   * @brief      Image filename sequance as vector
   */
  std::vector<cv::String> filenames_;
  /**
   * @brief      flag for video/simple image
   */
  bool imgSeq_;
};
