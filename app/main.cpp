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
#include <string>
#include "Robot.hpp"
/**
 * @brief      Main function
 *
 * @return     return zero if run properly
 */
int main(int argc, char *argv[]) {
    // Robot object init
    auto rb = std::make_unique<Robot>();
    // Check for input
    if (argc > 1) {
      std::string argument(argv[1]);
      // Robot setup method
      std::cout << "Main:" <<argument << std::endl;
      rb->setup(argument);
    } else {
#ifndef CAMERA_ENABLE
      rb->setup();
#else
      rb->setup(0);
#endif  // Hardware can be accessed by toggling the comment in
        // ../include/Camera.hpp and replace 0 with device ID
    }
    // Robot update method
    rb->update();

    return 0;
}
