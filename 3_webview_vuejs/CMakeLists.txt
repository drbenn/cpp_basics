cmake_minimum_required(VERSION 3.16)

# Define the project name
project(ExpenseEntryApp VERSION 1.0 LANGUAGES CXX)

# Set standard C++ version BEFORE finding packages
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CRITICAL: Enable Qt's automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt6 package and specifically require the 'WebEngineWidgets' module.
# This module provides the QWebEngineView class needed to render the web frontend.
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)

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

# Optional: Copy the expense_frontend/dist directory to the build directory
# This helps during development so you don't have to manually copy it
add_custom_command(TARGET ExpenseEntryApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/expense_frontend/dist
    $<TARGET_FILE_DIR:ExpenseEntryApp>/expense_frontend/dist
    COMMENT "Copying Vue.js dist folder to build directory"
)