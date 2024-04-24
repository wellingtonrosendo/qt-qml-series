cmake_minimum_required(VERSION 3.16)

project(qt-qml-series VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appqt-qml-series
    main.cpp
)

qt_add_qml_module(appqt-qml-series
    URI qt-qml-series
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES
        QML_FILES SearchField.qml
        QML_FILES
        SOURCES SeriesSearch.h SeriesSearch.cpp
        SOURCES tvseries.h tvseries.cpp
        SOURCES
        SOURCES
        SOURCES
        QML_FILES
        QML_FILES SerieInfo.qml
        QML_FILES HighLights.qml
        RESOURCES
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appqt-qml-series PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appqt-qml-series
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqt-qml-series
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appqt-qml-series
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
