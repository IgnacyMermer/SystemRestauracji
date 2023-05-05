cmake_minimum_required(VERSION 3.23)
project(projektPROI2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

include_directories(curlpp-0.8.1/include)
add_subdirectory(curlpp-0.8.1)
include_directories(json_spirit_v4.08/json_spirit)
add_subdirectory(json_spirit_v4.08)
FIND_PACKAGE(Boost 1.81 REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_executable(projektPROI2 main.cpp mainwindow.cpp mainwindow.h mainwindow.ui
        mainwindowloggedin.cpp mainwindowloggedin.h mainwindowloggedin.ui GetData.cpp GetData.h)

include_directories(client)
add_subdirectory(client)
include_directories(employees)
add_subdirectory(employees)
include_directories(meals)
add_subdirectory(meals)
include_directories(orders)
add_subdirectory(orders)

target_link_libraries(projektPROI2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        projektPROI2_client
        projektPROI2_employee
        projektPROI2_meal
        projektPROI2_order
        curlpp
        json_spirit
        ${Boost_LIBRARIES}
        )

