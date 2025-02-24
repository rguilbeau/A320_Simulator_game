find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Core
    Gui
    Quick
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    Gui
    Quick
)

add_executable(a320_simulator_game
    main.cpp
)

qt_add_qml_module(a320_simulator_game
    URI a320_simulator_game
    VERSION 1.0
    QML_FILES
        Main.qml
        qml/Fcu.qml
    SOURCES
        controller/main_controller.hpp
        controller/main_controller.cpp
        controller/fcu_controller.cpp
        controller/fcu_controller.hpp
)

add_subdirectory(frames)
add_subdirectory(cockpit_gateway)

target_link_libraries(a320_simulator_game
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Quick
        frame
        cockpit_gateway
)

target_include_directories(a320_simulator_game
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/controller
)

include(GNUInstallDirs)
install(TARGETS a320_simulator_game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
