/**
 * @file Camera.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once

template <class T>
/**
 * @brief      Virtual Class for every sensor.
 */
class Sensor {
 public:
    Sensor() {}
    virtual ~Sensor() {}
    virtual bool isOpened() = 0;
    virtual void update() = 0;
    virtual T getData() = 0;
};

// template <class T>
// Sensor<T>::~Sensor() {}
