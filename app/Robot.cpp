/**
 * @file Robot.cpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#include <Robot.hpp>

Robot::Robot() {
    detector_ = std::make_unique<Detection>();
    camera_ = std::make_unique<Camera>();
}

Robot::~Robot() {
}

auto Robot::setup() -> void {
    // TODO(raviBhadeshiya) : setup enviroment
}

auto Robot::update() -> void {
    // TODO(raviBhadeshiya) : update method
}

auto Robot::controller() -> void {
    // TODO(raviBhadeshiya) : Genrate controller signal
}
