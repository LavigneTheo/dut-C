#pragma once
#include <stdio.h>
#include "../exercise/Parfait.h"
#include "../exercise/Premier.h"
#include <sys/timeb.h>

void perf_test_1(const unsigned long number);
void save_data(const int* data, const char* file_name, const int array_size);
void run_test(const unsigned int number, int* data, Boolean(*function_premier)(unsigned long));
int get_diff(struct timeb start, struct timeb end);