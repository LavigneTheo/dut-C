#include "Parfait.h"
//tester si tomme est plus grand que n, faire attention  losrque sqrt(n) est ajouter 2 fois le test, utiliser conitnue?
Boolean parfait(unsigned long number) {
	long sum = 1;

	if (number % 2 == 0) {
		for (long i = 2; i <= sqrt(number); i++)
			if (number % i == 0)
				sum += i + number / i;
	}
	else {
		for (long i = 3; i <= sqrt(number); i += 2)
			if (number % i == 0)
				sum += i + number / i;
	}
	if ((int)sqrt(number) * (int)sqrt(number) == number)
		sum -= sqrt(number);

	if (sum == number)
		return TRUE;
	return FALSE;
}

void parfait_addr(unsigned long number, Boolean* premier) {
	long sum = 1;

	if (number % 2 == 0) {
		for (long i = 2; i <= sqrt(number); i++)
			if (number % i == 0)
				sum += i + number / i;
	}
	else {
		for (long i = 3; i <= sqrt(number); i += 2)
			if (number % i == 0)
				sum += i + number / i;
	}
	if ((int)sqrt(number) * (int)sqrt(number) == number)
		sum -= sqrt(number);

	if (sum == number)
		*premier = TRUE;
	*premier = FALSE;
}

void print_parfait_until(int limit) {
	for (long i = 0; i < limit; i++)
		if (parfait(i))

			printf("%d\n", i);
}

unsigned long long parfait_opti(int power) {
	if (premier_option4(pow(2, power) - 1))
		return pow(2, power - 1) * (pow(2, power) - 1);
	return 0;
}

void search_parfait(int number) {
	unsigned long found = 0, iterator = 0;
	while (found < number) {
		iterator++;
		if (parfait(iterator)) {
			printf("%lu\n", iterator);
			found++;
		}	
	}
}


