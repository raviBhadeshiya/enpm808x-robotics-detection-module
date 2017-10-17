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
#include <string>
#include "Detection.hpp"
#include "Camera.hpp"

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
     * @brief      Overloaded Setup method for video/image sequence
     *
     * @param[in]  arg  input string for video/input sequence
     *
     * @return     return none
     */
    auto setup(const std::string& arg) -> void;
    /**
     * @brief      Overloaded Setup method for video
     *
     * @param[in]  arg  input string for video
     *
     * @return     return none
     */
    auto setup(const int &deviceId) -> void;
    /**
     * @brief      Update method for updating everything
     *
     * @param[in]  display  The display as bool default true
     *
     * @return     return none
     */
    auto update(bool display = true) -> void;

 private:
    /**
     * @brief Detector as unique pointer
     */
    std::unique_ptr<Detection> detector_;
    /**
     * @brief Camera as unique pointer
     */
    std::unique_ptr<Camera> camera_;
    /**
     * @brief isSetup as boolean
     */
    bool isSetup_;
};
