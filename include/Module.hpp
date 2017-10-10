/**
 * @file Module.hpp
 * @author     Ravi Bhadeshiya
 * @version    1.0
 * @copyright  MIT License (c) 2017 Ravi Bhadeshiya
 */
#pragma once
/**
 * @brief      Virtual Class for every module.
 */
class Module {
 public:
    Module() {}
    virtual ~Module() {}
    virtual void update(void) = 0;
    virtual bool isSetup(void) = 0;
 private:
};
