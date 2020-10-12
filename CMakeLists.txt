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

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

#if(ANDROID)
#  add_library(ZipProj SHARED
#    main.cpp
#    mainwindow.cpp
#    mainwindow.h
#    mainwindow.ui
#  )
#else()
LINK_DIRECTORIES(".")

  add_executable(ZipProj
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    tzipviewermodel.cpp
    tzipviewermodel.h
    tcontroller.cpp
    tcontroller.h
    mz.h
    mz_compat.h
    mz_crypt.h
    mz_os.h
    mz_strm.h
    mz_strm_buf.h
    mz_strm_bzip.h
    mz_strm_libcomp.h
    mz_strm_lzma.h
    mz_strm_mem.h
    mz_strm_os.h
    mz_strm_pkcrypt.h
    mz_strm_split.h
    mz_strm_wzaes.h
    mz_strm_zlib.h
    mz_strm_zstd.h
    mz_zip.h
    mz_zip_rw.h
    unzip.h
    zconf.h
    zip.h
  )
#endif()

target_link_libraries(ZipProj PRIVATE Qt${QT_VERSION_MAJOR}::Widgets libminizip.lib zlibstaticd.lib zstd_static.lib)
