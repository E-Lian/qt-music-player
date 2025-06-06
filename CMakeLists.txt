cmake_minimum_required(VERSION 3.19)
project(qt-music-player LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt6 REQUIRED COMPONENTS Multimedia)

qt_standard_project_setup()

qt_add_executable(qt-music-player
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    PlayerControl.h
    PlayerControl.cpp
)

target_link_libraries(qt-music-player
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Multimedia
)

include(GNUInstallDirs)

install(TARGETS qt-music-player
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET qt-music-player
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
