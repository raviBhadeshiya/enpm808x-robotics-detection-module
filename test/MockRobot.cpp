/**
 * @file MockRobot.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>
#include "Robot.hpp"

/**
 * @brief      Robot class init check
 */
TEST(Robot, init) {
    // Check init
     auto robo = std::make_unique<Robot>();
}

/**
 * @brief      Robot setup check
 */
TEST(Robot, setup) {
    auto robo = std::make_unique<Robot>();
    // Check setup method
    EXPECT_NO_FATAL_FAILURE({robo->setup();});
    // Check overloaded setup
    EXPECT_NO_FATAL_FAILURE({robo->setup("../data/test/Lenna.png");});
}

/**
 * @brief      Robot class update check
 */
TEST(Robot, update) {
    auto robo = std::make_unique<Robot>();
    // Check setup
    EXPECT_NO_FATAL_FAILURE({robo->setup("../data/test/Lenna.png");});
    // Check update with display false
    // Since OpenCv window required waitkey
    // and Travic-ci can't provide any key stroke.
    EXPECT_NO_FATAL_FAILURE({ robo->update(false); });
}
