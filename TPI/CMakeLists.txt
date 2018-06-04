cmake_minimum_required(VERSION 3.8)
project(lecturaDeCerebros)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp solucion.cpp auxiliares.h auxiliares.cpp ejercicios.h definiciones.h tests/esValidaTEST.cpp tests/maximoTEST.cpp tests/mediaTEST.cpp tests/medianaEnteraTEST.cpp tests/histogramaTEST.cpp tests/ctrlfTEST.cpp tests/distanciaEuclidianaTEST.cpp tests/distanciaAcordeonTEST.cpp tests/slidingWindowsTEST.cpp tests/completarTEST.cpp tests/sacarOutliersTEST.cpp)
add_executable(lecturaDeCerebros ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

target_link_libraries(lecturaDeCerebros gtest gtest_main)
