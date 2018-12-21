#include <stdlib.h>
#include <stdio.h>
#include "exercise/Premier.h"
#include "exercise/Parfait.h"
#include "time/Time_diff.h"

void test_prem(Boolean(*fun)(unsigned long));
//laurent.delahoche@u-picardie.fr

int main() {
	
	print_parfait_until(10000);
	//printf("%d", premier_option6(49));
	//test_prem(&premier_option6);
	//premier_option3(101);
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
	printf("1 : %d\n", fun(23));
	printf("//0 : %d\n", fun(25));
	printf("1 : %d\n", fun(29));
	printf("1 : %d\n", fun(31));
	printf("1 : %d\n", fun(37));
	printf("1 : %d\n", fun(41));
	printf("1 : %d\n", fun(43));
	printf("1 : %d\n", fun(47));
	printf("//0 : %d\n", fun(49));
	printf("1 : %d\n", fun(53));
	printf("1 : %d\n", fun(59));
	printf("1 : %d\n", fun(61));
	printf("1 : %d\n", fun(67));
	printf("1 : %d\n", fun(71));
	printf("1 : %d\n", fun(73));
	printf("1 : %d\n", fun(79));
	printf("1 : %d\n", fun(83));
	printf("1 : %d\n", fun(89));
	printf("1 : %d\n", fun(97));
}
