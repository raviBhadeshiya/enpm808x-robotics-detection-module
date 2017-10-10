/**
 * @file Camera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
#include <memory>
#include <opencv2/opencv.hpp>
#include <Sensor.hpp>
/**
 * @brief      Class for camera inherited from sensor.
 */
class Camera : public Sensor<cv::Mat> {
 public:
    /**
     * @brief      Create the camera object
     */
    Camera();
    /**
     * @brief      Create specific the camera object
     *
     * @param[in]  id    The device identifier
     */
    explicit Camera(const int id);
    /**
     * @brief      Destroys the object.
     */
    ~Camera();
    /**
     * @brief      Determines if Camera running.
     *
     * @return     True if Camera running, False otherwise.
     */
    auto isRunning() -> bool;
    /**
     * @brief      Gets the data.
     *
     * @return     The data.
     */
    auto getData() -> cv::Mat;
    /**
     * @brief      Update method
     *
     * @return     return none
     */
    auto update() -> void;

 private:
    /**
     * @brief      video_capture_ as opencv video capture object
     */
    cv::VideoCapture video_capture_;
    /**
     * object running as bool
     */
    bool isRunning_;
    /**
     * Image as cv matric
     */
    cv::Mat data_;
};
