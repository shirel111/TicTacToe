cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe
    Main.cpp
    Game.cpp
    Board.cpp
    Game.h
    Board.h
)
target_compile_definitions(TicTacToe PRIVATE CI_MODE)