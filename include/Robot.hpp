/**
 * @file Robot.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 *
 * @brief Robot module for handling everthing
 *
 * @section DESCRIPTION
 * This little module demonstrate Deep Nerual Net based
 * detection module and camera module.It follow user friendly procedure
 * i.e. setup and update method for doing everything.
 */
#pragma once
#include <memory>
#include "Detection.hpp"
#include "Camera.hpp"

#define IMAGE_SEQUENCE  // Toogle comment for video sequence demo
/**
 * @brief      Class for robot
 */
class Robot {
 public:
    /**
     * @brief      Create the robot object
     */
    Robot();
    /**
     * @brief      Destroys the robot object
     */
    ~Robot();
    /**
     * @brief      Setup method
     *
     * @return     return none
     */
    auto setup() -> void;
    /**
     * @brief      Update method
     *
     * @return     return none
     */
    auto update() -> void;

 private:
    /**
     * @brief Detector as unique pointer
     */
    std::unique_ptr<Detection> detector_;
    /**
     * @brief Camera as unique pointer
     */
    std::unique_ptr<Camera> camera_;
};
