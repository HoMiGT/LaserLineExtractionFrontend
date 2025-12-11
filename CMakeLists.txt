cmake_minimum_required(VERSION 3.25)

project(CLineLaserExtract VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystemts/vcpkg.cmake" CACHE STRING "Path to toolchain file")
# set(CMAKE_PREFIX_PATH "D:/Softwares/Qt/6.8.3/mingw_64/lib/cmake/Qt6" CACHE PATH "Qt6 CMake dir")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core NetWork)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Network)
find_package(cpr CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB PROJECT_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.ui"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CLineLaserExtract
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET CLineLaserExtract APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CLineLaserExtract SHARED
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CLineLaserExtract
                ${PROJECT_SOURCES}
        )
    endif()
endif()

qt_add_resources(CLineLaserExtract
        PREFIX "/"
        FILES
        Icon/action_setting.svg
        Icon/add_task.svg
        Icon/clear_task.svg
        Icon/exit.svg
        Icon/menu_file.svg
        Icon/menu_help.svg
        Icon/no_ok.svg
        Icon/ok.svg
        Icon/preview.svg
        Icon/search.svg
        Icon/start_no.svg
        Icon/starting.svg
        Icon/stop.svg
        Pinyin/cnl.txt
)

target_link_libraries(CLineLaserExtract PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        cpr::cpr
        spdlog::spdlog_header_only
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CLineLaserExtract)
endif()
set_target_properties(CLineLaserExtract PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CLineLaserExtract
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CLineLaserExtract)
endif()
