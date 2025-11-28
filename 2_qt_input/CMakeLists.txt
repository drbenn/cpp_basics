cmake_minimum_required(VERSION 3.16)

# Define the project name
project(ExpenseEntryApp VERSION 1.0 LANGUAGES CXX)

# CRITICAL: Enable Qt's automatic MOC, UIC, and RCC processing
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find the Qt6 package and specifically require the 'Widgets' module
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set standard C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up the executable target
add_executable(ExpenseEntryApp 
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

# Link the executable against the required Qt module (Widgets)
target_link_libraries(ExpenseEntryApp PRIVATE Qt6::Widgets)

# Optional: Install the executable (for deployment)
install(TARGETS ExpenseEntryApp DESTINATION bin)