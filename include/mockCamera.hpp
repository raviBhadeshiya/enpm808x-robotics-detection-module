/**
 * @file mockCamera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "Camera.hpp"
/**
 * @brief      Class for mock camera.
 */
class mockCamera : public Camera {
 public:
  /**
   * @brief      Mock update method
   *
   * @param[in]  Function Name
   * @param[in]  Return type(args)
   */
  MOCK_METHOD0(update, void());
  /**
   * @brief      Mock isOpened method
   *
   * @param[in]  Function Name
   * @param[in]  Return type(args)
   */
  MOCK_METHOD0(isOpened, bool());
  /**
   * @brief      Mock getData method
   *
   * @param[in]  Function Name
   * @param[in]  Return type(args)
   */
  MOCK_METHOD0(getData, cv::Mat());
  /**
   * @brief      Mock getFileName method
   *
   * @param[in]  Function Name
   * @param[in]  Return type(args)
   */
  MOCK_METHOD0(getFilenames, std::vector<cv::String>());
};
