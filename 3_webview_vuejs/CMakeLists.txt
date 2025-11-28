cmake_minimum_required(VERSION 3.16)

# Define the project name
project(ExpenseEntryApp VERSION 1.0 LANGUAGES CXX)

# CRITICAL: Enable Qt's automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt6 package and specifically require the 'WebEngineWidgets' module.
# This module provides the QWebEngineView class needed to render the web frontend.
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)

# Set standard C++ version
target_compile_features(ExpenseEntryApp PRIVATE cxx_20)

# Set up the executable target.
# You will still need main.cpp and a QMainWindow class (e.g., mainwindow.cpp/h)
# to initialize the Qt application and the QWebEngineView.
qt_add_executable(ExpenseEntryApp 
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

# Link the executable against the required Qt module (WebEngineWidgets)
target_link_libraries(ExpenseEntryApp PRIVATE Qt6::WebEngineWidgets)

# Optional: Install the executable (for deployment)
install(TARGETS ExpenseEntryApp DESTINATION bin)