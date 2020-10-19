cmake_minimum_required(VERSION 3.5)

project(ZipProj LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
#set(CMAKE_CXX_FLAGS "-m32")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_subdirectory(${CMAKE_SOURCE_DIR}/3rdParty/minizip)


set (SOURCES main.cpp
    mainwindow.cpp
    tzipviewermodel.cpp
    tcontroller.cpp
    tcustomtablemodel.cpp
    )

set (HEADERS
    mainwindow.h
    tzipviewermodel.h
    tcontroller.h
    tcustomtablemodel.h
    )

set (UIS mainwindow.ui)

add_executable(ZipProj ${SOURCES} ${HEADERS} ${UIS} )


target_link_libraries(ZipProj PRIVATE Qt${QT_VERSION_MAJOR}::Widgets minizip z )
