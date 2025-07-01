cmake_minimum_required(VERSION 3.16)
project(UnoInTerminal CXX)

# Build configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-fsanitize=thread)
add_link_options(-fsanitize=thread)

include_directories(src)

add_executable(
    ${PROJECT_NAME}
    src/Card.cpp
    src/Card.hpp
    src/Game.cpp
    src/Game.hpp
    src/main.cpp
    src/Player.cpp
    src/Player.hpp
    src/utils.cpp
    src/utils.hpp
)

target_link_libraries(${PROJECT_NAME})
