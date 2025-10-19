cmake_minimum_required(VERSION 3.16)

project(YachtDice VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# ===== Include Directory =====
include_directories(include)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)
# ===== UI Files (명시적 등록) =====
set(UI_FILES
    ui/mainwindow.ui
)

# ===== Project Sources =====
set(PROJECT_SOURCES
    src/main.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    include/YachtCombination.h
    resources/resource.qrc
    ${UI_FILES}
)

# ===== Executable =====
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(YachtDice
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(YachtDice
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(YachtDice PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(YachtDice PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS YachtDice
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(YachtDice)
endif()
