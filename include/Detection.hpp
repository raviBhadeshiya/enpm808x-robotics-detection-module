/**
 * @file Detection.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once

#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Module.hpp>
/**
 * @brief      Class for object detection.
 */
class Detection : public Module {
 public:
    /**
     * @brief      Create a detector.
     */
    Detection();
    /**
     * @brief      Destroys the detector.
     */
    ~Detection();
    /**
     * @brief      Update method for updating every thing
     *
     * @return     return none
     */
    auto update() -> void;
    /**
     * @brief      Gets the objects.
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the detected object as image
     */
    auto getObjects(cv::Mat frame) -> cv::Mat;
    /**
     * @brief      Preprocess the image for clear detection
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the processed image as image
     */
    auto preProcess(cv::Mat frame) -> cv::Mat;
    /**
     * @brief      Render the bounding box over the object
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the rendered object as image
     */
    auto render(cv::Mat frame) -> cv::Mat;
    /**
     * @brief      Determines if setup
     *
     * @return     True if setup, False otherwise
     */
    auto isSetup(void) -> bool;

 private:
    /**
     * Vector of detected object
     */
    std::vector<cv::Mat> objects_;
    /**
     * Privious image frame for refrance/tracking
     */
    cv::Mat previous_frame_;
    /**
     * Is setup as bool
     */
    bool isSetup_;
};
