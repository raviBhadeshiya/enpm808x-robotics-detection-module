/**
 * @file Robot.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
#include <memory>
#include <Camera.hpp>
#include <Detection.hpp>
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
    /**
     * @brief      controller method
     *
     * @return     return none
     */
    auto controller() -> void;

 private:
    /**
     * Detector as unique pointer
     */
    std::unique_ptr<Detection> detector_;
    /**
     * Camera as unique pointer
     */
    std::unique_ptr<Camera> camera_;
};
