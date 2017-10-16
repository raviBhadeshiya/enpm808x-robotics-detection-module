/**
 * @file Camera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 *
 * @brief robotics_detection_module
 * @section DESCRIPTION
 * This is a little program will run the detection module.
 */
#include <iostream>
#include <memory>
#include "Robot.hpp"
/**
 * @brief      Main function
 *
 * @return     return zero if run properly
 */
int main() {
    // Robot object init
    auto rb = std::make_unique<Robot>();
    // Robot setup method
    rb->setup();
    // Robot update method
    rb->update();

  return 0;
}
