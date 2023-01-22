#!/bin/bash

g++ -c game_interface.cpp
g++ game_interface.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lm