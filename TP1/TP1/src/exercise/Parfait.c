#include "Parfait.h"

Boolean parfait(long number) {
	long sum = 1;

	if (number % 2 == 0) {
		for (long i = 2; i < sqrt(number); i++)
			if (number % i == 0)
				sum += i + number / i;
	}
	else {
		for (long i = 3; i < sqrt(number); i += 2)
			if (number % i == 0)
				sum += i + number / i;
	}
	if (sum == number)
		return TRUE;
	return FALSE;
}

void print_parfait_until(int limit) {
	for (long i = 0; i < limit; i++)
		if (premier_option4(i))

			printf("%d\n", i);
}

unsigned long long parfait_opti(int power) {
	if (premier_option4(pow(2, power) - 1))
		return pow(2, power - 1) * (pow(2, power) - 1);
	return 0;
}

void seach_parfait(int number) {
	
	int found = 0, iterator = 0;
	while (found < number) {
		iterator++;
		if (parfait_opti(iterator)) {
			printf("%llu\n", parfait_opti(iterator));
			found++;
		}
			
	}
}


