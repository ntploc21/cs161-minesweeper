# CS161 Project: Minesweeper

C++ project for CS161 Course.

## Introduction

This project is the Minesweeper game written in C++ language. It has all of the features of the Minesweeper game on https://minesweeper.online/.

### Features

- Drawing the board (including cells, mines and flags).
- Changing the state of each cell when it is selected.
- Timer.
- Functions: new game, change board dimensions. Select a function from console screen.
- Randomize positions of the mines.
- Receiving new position of the pointer (to select a cell) from console screen.
- Saving the current state of the board and loading in the next playing session.
- Saving high scores.

## Requirements

- C++20 (GNU GCC 11.3.0)
- CMake 3.14 or above
- [Raylib](https://github.com/raysan5/raylib)
- [Raygui](https://github.com/raysan5/raygui) (already included in this repo)
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)

## Building

- Clone this repository
- Install [Raylib on your platform](https://github.com/raysan5/raylib#build-and-installation)
- Install [yaml-cpp on your platform](https://github.com/jbeder/yaml-cpp/blob/master/install.txt)
- `cmake -S . -B ./build`
- `make -C build`
- The executable `minesweeper` will appear.

## Contributor

22125050 - Nguyen Thanh Phuoc Loc

ntploc21@gmail.com

https://www.facebook.com/ntploc.21/
