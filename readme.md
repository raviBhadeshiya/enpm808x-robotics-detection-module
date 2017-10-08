# Robotics detection modules
[![Build Status](https://travis-ci.org/raviBhadeshiya/enpm808x-robotics-detection-module.svg?branch=master)](https://travis-ci.org/raviBhadeshiya/enpm808x-robotics-detection-module)
[![Coverage Status](https://coveralls.io/repos/github/raviBhadeshiya/enpm808x-robotics-detection-module/badge.svg?branch=master)](https://coveralls.io/github/raviBhadeshiya/enpm808x-robotics-detection-module?branch=master)
---


## Overview

Midterm Project for ENPM808x:
- opencv
- cmake
- googletest

## Standard install via command-line
```
git clone --recursive https://github.com/dpiet/cpp-boilerplate
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.
