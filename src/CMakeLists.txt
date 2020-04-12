# Reference:
# https://www.apriorit.com/dev-blog/475-qt-qml-with-cmake

# The header files should be included. In makefile compilation
# Qt5Widgets stands the header files for Qt framework.
# QtQml invokes special files for QML functions.
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})

# definitions must be specified in makefile compilation commands:
add_definitions(
  ${Qt5Widgets_DEFINITIONS} 
  ${QtQml_DEFINITIONS}
  ${${Qt5Quick_DEFINITIONS}})

# 
qt5_add_resources(QT_RESOURCES qml/qml.qrc)

# If the project includes GUI:
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Just add for Qt programs(1):
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Project name (name of the generated executable):
set(PROJECT "SmallTestsQml")

# Set the project within the cmake file?!?
project(${PROJECT})

# These flags set very strict compilation rules and help 
# to detect and locate a lot of potential issues during compilation:
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -fstrict-aliasing -pedantic-errors -pedantic -Wno-deprecated-declarations -Wno-unused-variable")

# A list of all header files in current directory, passed as header files of 
# current project:
if(NOT DEFINED HEADERS)
    file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
endif()

# A list of all source files in current directory, passed as source files of 
# current project:
if(NOT DEFINED SOURCES)
    file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
endif()
#source_group("Header Files" FILES ${HEADERS})
#source_group("Source Files" FILES ${SOURCES})

# Executable file: 
add_executable(${PROJECT} # executable file name (Equal to project name in here)
  ${HEADERS} # header files 
  ${SOURCES} # source files
  ${QT_RESOURCES}) # Compiled qt resources

# Link libraries to generated executable:
target_link_libraries(${PROJECT}
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick)
