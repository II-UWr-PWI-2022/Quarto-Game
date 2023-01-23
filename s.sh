#!/bin/bash

mkdir -p build

cd src

gcc Console_user_interface.cpp -c
gcc Piece.cpp -c
gcc Quarto_game.cpp -c
gcc Bot_random.cpp -c
gcc Bot_template.cpp -c
gcc Bot_minmax.cpp -c
gcc Bot_superior.cpp -c

g++ -g -std=c++17 -O3 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector 'main.cpp' -o 'main' Quarto_game.o Piece.o Console_user_interface.o Bot_random.o Bot_minmax.o Bot_superior.o Bot_template.o -lm

mv *.o ../build
mv main ../build

cd ..