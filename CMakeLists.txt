project(fast16)
cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unknown-pragmas")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mmmx -msse -msse -msse2 -msse3 -mssse3 -fomit-frame-pointer")

find_package(catkin_simple REQUIRED)
catkin_simple()

set(HEADERS
  include/fast16/corner_10.h
  include/fast16/fast16.h
  include/fast16/faster_corner_utilities.h
)

set(SOURCES
  src/fast16_10.cpp
  src/fast16_10_score.cpp
  src/nonmax_3x3.cpp
)

# LIST(APPEND SOURCES ${PROJECT_SOURCE_DIR}/src/faster_corner_10_sse.cpp)

cs_add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

################################################################################
cs_install()
cs_export()
