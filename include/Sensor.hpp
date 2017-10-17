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
    /**
     * @brief      Create the object.
     */
    Sensor() {}
    /**
     * @brief      Destroys the object.
     */
    virtual ~Sensor() {}
    /**
     * @brief      Determines if opened.
     *
     * @return     True if opened, False otherwise.
     */
    virtual bool isOpened() = 0;
    /**
     * @brief      Virtual update method
     */
    virtual void update() = 0;
    /**
     * @brief      Gets the data.
     *
     * @return     The data as template.
     */
    virtual T getData() = 0;
};
