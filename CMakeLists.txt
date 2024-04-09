cmake_minimum_required(VERSION 3.5)

project(student_manage_system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Charts )



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        CSVTool.cpp
        CSVTool.h
        databaseconnectiondialog.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(student_manage_system
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        sidebar.h sidebar.cpp sidebar.ui
        studentwidget.h studentwidget.cpp studentwidget.ui
        statisticwidget.h statisticwidget.cpp statisticwidget.ui
        indexwidget.h indexwidget.cpp indexwidget.ui
        scorewidget.h scorewidget.cpp scorewidget.ui
        comboboxdelegate.h comboboxdelegate.cpp
        scorechangedialog.h scorechangedialog.cpp scorechangedialog.ui
        titlebar.h titlebar.cpp titlebar.ui
        resource.qrc
        loginwindow.h loginwindow.cpp loginwindow.ui
        circleprogressbar.h circleprogressbar.cpp circleprogressbar.ui
        aligncenterdelegate.h aligncenterdelegate.cpp
        logo.rc
        genshin_impact.ico
            spinboxdelegate.h spinboxdelegate.cpp
            properties.h properties.cpp
            databaseconnectiondialog.h databaseconnectiondialog.cpp databaseconnectiondialog.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET student_manage_system APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(student_manage_system SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(student_manage_system
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(student_manage_system PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Sql
        Qt${QT_VERSION_MAJOR}::Charts
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.student_manage_system)
endif()
set_target_properties(student_manage_system PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS student_manage_system
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(student_manage_system)
endif()
#target_include_directories(student_manage_system PUBLIC /Users/anishan/Project/qt/student_manage_system/sidebar.h)
include_directories(./)
