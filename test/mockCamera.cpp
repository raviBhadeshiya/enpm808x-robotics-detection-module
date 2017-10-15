/**
 * @file mockCamera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include "mockCamera.hpp"

TEST(Camera, init) {
    auto cam = std::make_unique<Camera>();
    // cam = std::make_unique<Camera>
    // ("data/MobileNetSSD_deploy");   // invalid file check
}

TEST(Camera, imgSeq_check) {
    auto cam = std::make_unique<Camera>("../data/*.png");
    auto expected = cv::imread("../data/Lenna.png");

    ASSERT_FALSE(expected.empty());
    // ASSERT_FALSE(cv::norm(cam->getData(), expected, cv::NORM_L2));
    EXPECT_EQ(0,
        cv::norm(cam->getData(), expected, cv::NORM_L2));
    // auto result = cam->getData();
    // ASSERT_TRUE(expected.empty());
}

TEST(Camera, video_check) {
    auto cam = std::make_unique<Camera>("../data/vtest.avi");
    auto result = cam->getData();
    ASSERT_FALSE(result.empty());
}
