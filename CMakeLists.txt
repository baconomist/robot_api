set(VERSION "2.8.4") # Create var "VERSION"
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*) # Create var "SOURCE_FILES", I guess init.c is enough cus anything linked to it is compiled?

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})
project(RobotAPI CXX C)

file(GLOB SOURCES "src/*.c" "src/*.h" "src/*.cpp" "src/*.hpp")

# Include PROS headers
include_directories(RobotAPI "${CMAKE_CURRENT_SOURCE_DIR}/../include")
# Build RobotAPI as library
add_library(RobotAPI STATIC ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR})
# Include SharedAPI and Robot
target_link_libraries(RobotAPI SharedAPI)
target_link_libraries(RobotAPI Robot)

# https://stackoverflow.com/questions/28597351/how-do-i-add-a-library-path-in-cmake
# https://stackoverflow.com/questions/38858275/how-to-import-a-file-to-cmake-in-c
# Add firmware/ libraries
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libpros.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/okapilib.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libm.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libc.a")
