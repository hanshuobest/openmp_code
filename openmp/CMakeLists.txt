cmake_minimum_required (VERSION 3.5.1)

set (CMAKE_CXX_STANDARD 11)
project( main )

find_package( OpenMP )
find_package( OpenCV REQUIRED )
If (APPLE)
   find_package(spdlog CONFIG REQUIRED)
   include_directories(${spdlog_DIR}/../../../include)
endif(APPLE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-write-strings")

include_directories(.)
add_executable( main main.cpp)
add_executable( test_for openmp_for.cpp )
#target_link_libraries( main PRIVATE ${OpenCV_LIBS} pthread)

if(OpenMP_CXX_FOUND)
    target_link_libraries(main PUBLIC ${OpenCV_LIBS} OpenMP::OpenMP_CXX)
    target_link_libraries(test_for PUBLIC ${OpenCV_LIBS} pthread OpenMP::OpenMP_CXX)
else()
    target_link_libraries(main PUBLIC ${OpenCV_LIBS})    
    target_link_libraries(test_for PUBLIC ${OpenCV_LIBS} pthread )
endif()
