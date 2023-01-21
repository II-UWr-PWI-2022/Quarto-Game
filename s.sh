#!/bin/bash

mkdir -p build

cd src

gcc Console_user_interface.cpp -c
gcc Piece.cpp -c
gcc Quarto_game.cpp -c

g++ -g -std=c++17 -O3 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector 'main.cpp' -o 'main' Quarto_game.o Piece.o Console_user_interface.o -lm

mv *.o ../build
mv main ../build

cd ..