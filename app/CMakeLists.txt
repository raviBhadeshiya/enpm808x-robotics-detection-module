add_executable(shell-app main.cpp Camera.cpp Detection.cpp Robot.cpp)
# Link the OpenCV_LIBS with binary
target_link_libraries( shell-app ${OpenCV_LIBS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
