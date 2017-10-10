/**
 * @file lib.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void dummy() {
  cv::Mat image;

  image = cv::imread("data/Lenna.png", CV_LOAD_IMAGE_COLOR);

  if (!image.data) {
    std::cout << "image not found!!" << std::endl;
    return;
  }

  cv::namedWindow("Display Window", cv::WINDOW_AUTOSIZE);

  cv::imshow("Display Window", image);

  cv::waitKey();
}
