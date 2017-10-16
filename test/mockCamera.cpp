/**
 * @file mockCamera.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include "mockCamera.hpp"

TEST(Camera, init) {
  auto cam = std::make_unique<Camera>();  // init check
}

TEST(Camera, imgSeq_check) {
  // Read png files
  auto cam = std::make_unique<Camera>("../data/*.png");
  // Expected png file
  auto expected = cv::imread("../data/Lenna.png");
  ASSERT_FALSE(expected.empty());
  // If two image is equal than norm would be zero
  EXPECT_EQ(0, cv::norm(cam->getData(), expected, cv::NORM_L2));
}

TEST(Camera, video_check) {
  // Abillity to read video files
  auto cam = std::make_unique<Camera>("../data/vtest.avi");
  auto result = cam->getData();
  // Check valid frame
  ASSERT_FALSE(result.empty());
}
