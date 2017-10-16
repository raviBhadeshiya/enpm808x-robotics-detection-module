/**
 * @file main.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <gtest/gtest.h>
#include "mockCamera.hpp"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
