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
qt_add_executable(ExpenseEntryApp 
    main.cpp
    mainwindow.cpp
    mainwindow.h
    urlschemehandler.h
)

# Link the executable against the required Qt module (WebEngineWidgets)
target_link_libraries(ExpenseEntryApp PRIVATE Qt6::WebEngineWidgets)

# Optional: Install the executable (for deployment)
install(TARGETS ExpenseEntryApp DESTINATION bin)

# Optional: Copy the expense-frontend/dist directory to the build directory (if it exists)
# This helps during development so you don't have to manually copy it
if(EXISTS ${CMAKE_SOURCE_DIR}/expense-frontend/dist)
    add_custom_command(TARGET ExpenseEntryApp POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:ExpenseEntryApp>/expense-frontend
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/expense-frontend/dist
        $<TARGET_FILE_DIR:ExpenseEntryApp>/expense-frontend/dist
        COMMENT "Copying Vue.js dist folder to build directory"
        VERBATIM
    )
else()
    message(WARNING "Vue.js dist folder not found at ${CMAKE_SOURCE_DIR}/expense-frontend/dist")
endif()