cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project( barcode_demo )

# use unicode
add_definitions(-DUNICODE -D_UNICODE) 

# set library and include path
if(UNIX)
    find_package(OpenCV REQUIRED)
else()
    set(OpenCV_LIBS "C:\\opencv\\build\\x64\\vc14\\lib\\opencv_world310.lib") 
    set(OpenCV_INCLUDE_DIRS "C:\\opencv\\build\\include")
endif()

add_executable(barcode_demo 
                barcode_demo.cpp 
                BarcodeDetector.cpp
                BarcodeDecoder.cpp)
target_include_directories(barcode_demo PRIVATE ${OpenCV_INCLUDE_DIRS} ) 
target_link_libraries(barcode_demo ${OpenCV_LIBS})
