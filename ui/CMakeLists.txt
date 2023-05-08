project(projektPROI2)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(projektPROI2_ui yourdata.cpp yourdata.h yourdata.ui
        mainwindowloggedin.cpp mainwindowloggedin.h mainwindowloggedin.ui
        mainwindow.cpp mainwindow.h mainwindow.ui)

target_link_libraries(projektPROI2_ui
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

