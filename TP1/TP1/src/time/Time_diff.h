#pragma once
#include <stdio.h>
#include "../exercise/Parfait.h"
#include "../exercise/Premier.h"
#include <sys/timeb.h>

void perf_test_1(const unsigned long number);
void save_data(const int* data, const char* file_name, const int array_size);
void run_test1(const unsigned long number, int* data, Boolean(*function_premier)(unsigned long));
void run_test2(const unsigned long number, int* data, Boolean(*function_premier)(unsigned long));