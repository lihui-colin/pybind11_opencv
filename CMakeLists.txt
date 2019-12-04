project(Test_pybind11)

#**************************************************************************************************
# General cMake settings
#**************************************************************************************************
cmake_minimum_required(VERSION 3.5)

#**************************************************************************************************
# Find Package **************************************************************************************************
# find_package(OpenCV REQUIRED)
# MESSAGE( " *** OpenCV_INCLUDE_DIRS : " ${OpenCV_INCLUDE_DIRS} )
# MESSAGE( " *** OpenCV_LIB_DIRS : " ${OpenCV_LIB_DIRS} )
# MESSAGE( " *** OpenCV_LIBS : " ${OpenCV_LIBS} )

# find_package(PythonLibs 3 REQUIRED)
# MESSAGE( " *** PYTHON_INCLUDE_DIRS : " ${PYTHON_INCLUDE_DIRS} )
# MESSAGE( " *** PYTHON_LIBRARIES : " ${PYTHON_LIBRARIES} )

# find_package(pybind11 CONFIG REQUIRED)
set(PYTHON_INCLUDE_DIRS /data/colinhli/anaconda3/envs/python36/include/python3.6m/)
set(3rdparty ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)
set(OpenCV_LIBS opencv_imgcodecs.a opencv_imgproc.a opencv_core.a)


#**************************************************************************************************
# Include **************************************************************************************************
include_directories(${PYTHON_INCLUDE_DIRS})
# include_directories(${OpenCV_INCLUDE_DIRS})
# include_directories(${OpenCV_INCLUDE_DIRS}/opencv4)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# include_directories(${pybind11_INCLUDE_DIR})
include_directories(/usr/include/eigen3)
 
include_directories(${3rdparty}/include)
link_directories(${3rdparty}/lib)

#**************************************************************************************************
# Set variable **************************************************************************************************
SET(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/auxo_cv.cpp
  # ${CMAKE_CURRENT_SOURCE_DIR}/ndarray_converter.cpp
)

#**************************************************************************************************
# Set compiler **************************************************************************************************
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -O3 -fPIC")

#**************************************************************************************************
# Linker **************************************************************************************************
# LINK_DIRECTORIES(
#   ${OpenCV_LIB_DIR}
# )

#**************************************************************************************************
# Make configuration
#**************************************************************************************************
add_library(AuxoCv SHARED ${SOURCES})
target_link_libraries(AuxoCv -Wl,--whole-archive libpng libtiff libjpeg -Wl,--no-whole-archive ${PYTHON_LIBRARIES} ${OpenCV_LIBS} libwebp zlib)
SET_TARGET_PROPERTIES(AuxoCv PROPERTIES PREFIX "")

install(TARGETS AuxoCv DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_library(ReturnValue SHARED return_value.cpp)
SET_TARGET_PROPERTIES(ReturnValue PROPERTIES PREFIX "")
install(TARGETS ReturnValue DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})