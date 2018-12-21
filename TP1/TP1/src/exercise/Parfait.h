#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Premier.h"

Boolean parfait(unsigned long number);
void parfait_addr(unsigned long number, Boolean* premier);
unsigned long long parfait_opti(int power);
void print_parfait_until(int limit);
void search_parfait(int number);