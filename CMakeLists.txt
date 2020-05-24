# References
# https://www.apriorit.com/dev-blog/475-qt-qml-with-cmake

cmake_minimum_required(VERSION 2.8)

#Third party tools:
find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)
find_package(Qt5Charts)
# Directory with source code:
add_subdirectory(src)


