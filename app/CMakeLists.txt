SET(OPENCV_DNN_SAMPLES_REQUIRED_DEPS opencv_core opencv_imgproc opencv_dnn opencv_imgcodecs opencv_videoio opencv_highgui ${OpenCV_LIB_COMPONENTS})

add_executable(shell-app main.cpp Camera.cpp Detection.cpp Robot.cpp)
# Link the OpenCV_LIBS with binary
target_link_libraries( shell-app ${OPENCV_DNN_SAMPLES_REQUIRED_DEPS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
