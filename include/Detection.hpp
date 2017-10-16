/**
 * @file Detection.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 *
 * @brief Deep Nerual Net based Detection Module
 *
 * @section DESCRIPTION
 * This detection module first preprocess input image and
 * detect multiple object with help of pre-trained deep nerual net.
 * The nerual net can be trained for customized image.
 * The deep learning-based object detector can process
 * approximately 10-15 FPS (depending on the speed of your system)
 *
 * @cite This sample uses <a href="https://arxiv.org/abs/1512.02325">Single-Shot Detector</a>
 * to detect objects on image. For more info:
 * <a href="https://github.com/weiliu89/caffe/tree/ssd#models">Click Here</a>
 *
 */
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "Module.hpp"

#define DEBUG_DETCTION
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
     * @brief      Overloaded constructor for defining parameter
     *
     * @param[in]  modelConfig  The model configuration
     * @param[in]  binary       The binary
     * @param[in]  importAlso   The import also
     */
    Detection(const cv::String& modelConfig, const cv::String& binary);
    /**
     * @brief      Destroys the detector.
     */
    ~Detection();
    /**
     * @brief      Update method for updating every thing
     *
     * @param[in]  frame  The frame as image
     *
     * @return     return image with detected content if any
     */
    auto update(const cv::Mat& frame) -> cv::Mat;
    /**
     * @brief      Overloaded Update method for updating every thing for internal image
     *
     * @return     return image with detected content if any
     */
    auto update() -> void;
    /**
     * @brief      Gets the objects.
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the detected object as image
     */
    auto getObjects(const cv::Mat& frame) -> cv::Mat;
    /**
     * @brief      Preprocess the image for clear detection
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the processed image as image
     */
    auto preProcess(const cv::Mat& frame) -> cv::Mat;
    /**
     * @brief      Render the bounding box over the object
     *
     * @param[in]  frame  Input frame as image
     *
     * @return     return the rendered object as image
     */
    auto render(cv::Mat frame, const cv::Mat& detectionMat) -> cv::Mat;
    /**
     * @brief      Determines if setup
     *
     * @return     True if setup, False otherwise
     */
    auto isSetup(void) -> bool;
    /**
     * @brief      Gets the mean.
     *
     * @param[in]  width   The width
     * @param[in]  height  The height
     *
     * @return     The mean as image
     */
    auto getMean(const int& width, const int& height) ->  cv::Mat;
    /**
     * @brief      Refactored function for importing
     *
     * @return     Return none
     */
    auto import() -> void;

 private:
    /**
     * @brief      Is setup as bool
     */
    bool isSetup_;
    /**
     *@brief      Model configuration as prototxt
     */
    cv::String modelConfiguration_;
    /**
     * @brief      Model binary as caffemodel
     */
    cv::String modelBinary_;
    /**
     * @brief      Image frame for refrance/tracking
     */
    cv::Mat frame_;
    /**
     *@brief      Deep Neural Net as opencv net
     */
    cv::dnn::Net net_;
    /**
     *@brief      Const Int as image width
     */
    const int WIDTH_ = 300;
    /**
     *@brief      Const Int as image height
     */
    const int HEIGHT_ = 300;
    /**
     *@brief      Const flaot as detection confidenceThreshold
     */
    const float confidenceThreshold_ = 0.5;
    /**
     *@brief      Const Int as input image width
     */
    const size_t inWidth_ = 300;
    /**
     *@brief      Const Int as inpput image height
     */
    const size_t inHeight_ = 300;
    /**
     *@brief      Const float as inScaleFactor for blob
     */
    const float inScaleFactor_ = 0.007843f;
    /**
     *@brief      Const float as meanVal for blob
     */
    const float meanVal_ = 127.5;
    /**
     * @brief      Vector of detected objects
     */
    std::vector<cv::Mat> objects_;
    /**
     * @brief      Detected object label as string vector
     */
    std::vector<cv::String> classNames_ = {
        "background", "aeroplane",   "bicycle", "bird",  "boat",
        "bottle",     "bus",         "car",     "cat",   "chair",
        "cow",        "diningtable", "dog",     "horse", "motorbike",
        "person",     "pottedplant", "sheep",   "sofa",  "train",
        "tvmonitor"};
};
