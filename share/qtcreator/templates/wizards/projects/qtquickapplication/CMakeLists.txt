cmake_minimum_required(VERSION 3.16)

project(%{ProjectName} VERSION 0.1 LANGUAGES CXX)

@if !%{HasQSPSetup}
set(CMAKE_AUTOMOC ON)
@endif
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 %{MinimumSupportedQtVersion} REQUIRED COMPONENTS Quick)

@if %{HasQSPSetup}
@if %{UsesAutoResourcePrefix}
qt_standard_project_setup(REQUIRES 6.5)
@else
qt_standard_project_setup()
@endif
@endif

qt_add_executable(%{TargetName}
    main.cpp
)

qt_add_qml_module(%{TargetName}
    URI %{ProjectName}
    VERSION 1.0
    QML_FILES Main.qml
)

set_target_properties(%{TargetName} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(%{TargetName}
    PRIVATE Qt6::Quick
)

install(TARGETS %{TargetName}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
