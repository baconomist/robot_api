set(VERSION "2.8.4") # Create var "VERSION"
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*) # Create var "SOURCE_FILES", I guess init.c is enough cus anything linked to it is compiled?

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})
project(RobotAPI CXX C)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Include PROS headers
include_directories(RobotAPI "${CMAKE_CURRENT_SOURCE_DIR}/../include")
# Build RobotAPI as library
add_library(RobotAPI STATIC ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR})

# Include SharedAPI and Robot
# Include SharedAPI
target_link_libraries(RobotAPI SharedAPI)
target_link_libraries(RobotAPI Robot)

# https://stackoverflow.com/questions/28597351/how-do-i-add-a-library-path-in-cmake
# https://stackoverflow.com/questions/38858275/how-to-import-a-file-to-cmake-in-c
# Add firmware/ libraries
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libpros.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/okapilib.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libm.a")
target_link_libraries(RobotAPI exec "${CMAKE_CURRENT_SOURCE_DIR}/../firmware/libc.a")

# Remove prefix
set_target_properties(RobotAPI PROPERTIES PREFIX "")
# Change DLL filename
set_target_properties(RobotAPI PROPERTIES OUTPUT_NAME "libRobotAPI")