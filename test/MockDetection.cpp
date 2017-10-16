/**
 * @file mockDetection.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Detection.hpp"

// Check the init
TEST(Detection, init) {
    // Unique pointer
    auto detector = std::make_unique<Detection>();
    // detector = std::make_unique<Detection>(
    //     "../data/MobileNetSSD_deploy.prototxt",
    //     "../data/MobileNetSSD_deploy.caffemodel");
    // Should update without any error
    EXPECT_NO_THROW(detector->update());
}

TEST(Detection, detector) {
    // Unique pointer
    auto detector =
    std::make_unique<Detection>(
        "../data/MobileNetSSD_deploy.prototxt",
        "../data/MobileNetSSD_deploy.caffemodel");
    // Read specific image and check
    auto expected = cv::imread("../data/Lenna.png");
    // update method
    expected = detector->update(expected);
    // If something detected, image should change
    // Compare diff by norm
    ASSERT_TRUE(cv::norm(expected,
        cv::imread("../data/Lenna.png"), cv::NORM_L2));
}
