project(projektPROI2)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(projektPROI2_ui
        addingredient.cpp addingredient.h addingredient.ui
        orderdetails.cpp orderdetails.h orderdetails.ui
        ordersediting.cpp ordersediting.h ordersediting.ui
        clientdetails.cpp clientdetails.h clientdetails.ui
        addtasks.cpp addtasks.h addtasks.ui
        taskdetails.cpp taskdetails.h taskdetails.ui
        yourorderdetails.cpp yourorderdetails.h yourorderdetails.ui
        mealdetails.cpp mealdetails.h mealdetails.ui
        yourdata.cpp yourdata.h yourdata.ui
        yourorders.cpp yourorders.h yourorders.ui
        yourclients.cpp yourclients.h yourclients.ui
        addnewmeal.cpp addnewmeal.h addnewmeal.ui
        addnewdrinksauce.cpp addnewdrinksauce.h addnewdrinksauce.ui
        mealsediting.cpp mealsediting.h mealsediting.ui
        mainwindowloggedinclient.cpp mainwindowloggedinclient.h mainwindowloggedinclient.ui
        mainwindowloggedin.cpp mainwindowloggedin.h mainwindowloggedin.ui
        mainwindow.cpp mainwindow.h mainwindow.ui)

target_link_libraries(projektPROI2_ui
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
