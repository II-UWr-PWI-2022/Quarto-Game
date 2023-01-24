#ifndef LIBRARIES_AND_MACROS_H
#define LIBRARIES_AND_MACROS_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <vector>
#include <assert.h>
#include <thread>

#define wait(x) this_thread::sleep_for((x)*1ms);

#if defined(_WIN32) || defined(_WIN64)
#define clear_console() system("cls")
#else
#define clear_console() system("clear")
#endif

using namespace std;

const int MAX_N = 4;
const int MAX_NUMBER_OF_PIECES = 16;
const int EMPTY_FIELD = 16;
const int MASK = 15;

const int HUMAN = 0;
const int BOT_1 = 1;
const int BOT_2 = 2;
const int BOT_3 = 3;

#endif