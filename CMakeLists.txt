cmake_minimum_required(VERSION 3.8)
project(LoadingBar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include_directories(cmake_modules)

add_subdirectory(tests/lib/googletest-master)
include_directories(tests/lib/googletest-master/googletest/include)
include_directories(tests/lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Frame.cpp Frame.h AbstractSubject.cpp AbstractSubject.h Observer.h LoadingHandler.cpp LoadingHandler.h Simpletest.cpp MainFrame.cpp MainFrame.h)
add_executable(LoadingBar ${SOURCE_FILES})

find_package(wxWidgets COMPONENTS net gl core base)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
    # and for each of your dependent executable/library targets:
    target_link_libraries(LoadingBar ${wxWidgets_LIBRARIES})
    target_link_libraries(LoadingBar gtest gtest_main)
endif()

