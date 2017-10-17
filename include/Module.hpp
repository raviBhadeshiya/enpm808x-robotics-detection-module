/**
 * @file Module.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
/**
 * @brief      Virtual Class for detection module.
 */
class Module {
 public:
    /**
     * @brief      Create the object.
     */
    Module() {}
    /**
     * @brief      Destroys the object.
     */
    virtual ~Module() {}
    /**
     * @brief      Virtual update method.
     */
    virtual void update(void) = 0;
    /**
     * @brief      Determines if setup virtual.
     *
     * @return     True if setup, False otherwise.
     */
    virtual bool isSetup(void) = 0;
 private:
};
