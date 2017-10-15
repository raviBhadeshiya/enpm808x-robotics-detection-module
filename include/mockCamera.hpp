/**
 * @file mockCamera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include "Camera.hpp"

class mockCamera : public Camera {
 public:
  MOCK_METHOD0(update, void());
  MOCK_METHOD0(isOpened, bool());
  MOCK_METHOD0(getData, cv::Mat());
  MOCK_METHOD0(getFilenames, std::vector<cv::String>());
};
