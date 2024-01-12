cmake_minimum_required(VERSION 3.1)

project(SnakeCpp VERSION 1.0
                  DESCRIPTION "Snake Game for commandline"
                  LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)

set (CMAKE_CXX_STANDARD 11)

set(CPP_FILES ${PROJECT_SOURCE_DIR}/Private/RingBuffer.cpp
${PROJECT_SOURCE_DIR}/Private/GraphicOutput.cpp
${PROJECT_SOURCE_DIR}/Private/GraphicElement.cpp
${PROJECT_SOURCE_DIR}/Private/Input.cpp
${PROJECT_SOURCE_DIR}/Private/snakeElement.cpp
${PROJECT_SOURCE_DIR}/Private/SnakeGame.cpp
)
set(GAME_CPP ${CPP_FILES} Private/main.cpp)

add_executable(snake ${GAME_CPP})
target_include_directories(snake PUBLIC Public/)
target_link_libraries(snake pthread ncurses)


add_executable(test ${CPP_FILES} tests/tests.cpp)
target_include_directories(test PUBLIC Public doctest/doctest)
target_link_libraries(test pthread ncurses)
