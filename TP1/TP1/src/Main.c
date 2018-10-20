#include <stdlib.h>
#include <stdio.h>
#include "exercise/Premier.h"
#include "exercise/Parfait.h"
#include "time/Time_diff.h"

void test_prem(Boolean(*fun)(unsigned long));

int main() {
	
	perf_test_2(100000);
	
	return;
}


void test_prem(Boolean(*fun)(unsigned long)) {
	printf("1 : %d\n", fun(3));
	printf("1 : %d\n", fun(5));
	printf("1 : %d\n", fun(7));
	printf("0 : %d\n", fun(9));
	printf("1 : %d\n", fun(11));
	printf("1 : %d\n", fun(13));
	printf("0 : %d\n", fun(15));
	printf("1 : %d\n", fun(17));
	printf("1 : %d\n", fun(19));
	printf("0 : %d\n", fun(21));
}