#include "Premier.h"

/*
 * Aucune optimisation
 */
Boolean premier_option0(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2)
		return TRUE;

	for (long i = 3; i < number; i++)
		if (number % i == 0)
			return FALSE;
	return TRUE;
}

/*
 * Exclure les nombres divisible par deux avant la recherche de primalité
 */
Boolean premier_option1(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2)
		return TRUE;
	if (number % 2 == 0)
		return FALSE;

	for (long i = 3; i < number; i+=2)
		if (number % i == 0)
			return FALSE;
	return TRUE;
}

/*
 * Arreter la recherche lorsque les diviseurs sont supérieur à la racine carrée de 'number'
*/
Boolean premier_option2(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2)
		return TRUE;

	for (long i = 3; i <= sqrt(number); i++)
		if (number % i == 0)
			return FALSE;
	return TRUE;
}


/*
 * Exclure les multiples de 2 et de 3 lors du test de divisibilite
*/
Boolean premier_option3(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2 || number == 3)
		return TRUE;
		if (number % 2 == 0 || number % 3 == 0)
			return FALSE;

	int pas = 4;
	for (long i = 5; i < number; i+= (pas = 6 - pas))
		if (number % i == 0)
			return FALSE;
	return TRUE;
}

/* 
 * Enlever la condition testant si i est multiple du nombre
*/
Boolean premier_option4(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2)
		return TRUE;

	unsigned long i = 3;
	for (i; number % i; i++);
	
	if (i == number)
		return TRUE;
	return FALSE;
}

/*
 * Optimisation proposé par l'énoncé
 */
Boolean premier_option5(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2)
		return TRUE;
	if (number % 2 == 0)
		return FALSE;

	for (long i = 3; i <= sqrt(number); i += 2)
		if (number % i == 0)
			return FALSE;
	return TRUE;
}


/*
 * Optimisation proposé par l'énoncé plus retirer les multiples de 3 ainsi que le test
 * de divisibilité au sein de la boucle
 */
Boolean premier_option6(unsigned long number) {
	if (number < 2)
		return FALSE;
	if (number == 2 || number == 3)
		return TRUE;
	if (number % 2 == 0 || number % 3 == 0)
		return FALSE;

	unsigned long i = 5;
	int pas = 4;

	for (i; i < sqrt(number) + 1 && (number % i); i += (pas = 6 - pas));
	
	if (i >= sqrt(number) + 1)
		return TRUE;
	return FALSE;
}

/*
 * 
 */
void premier_option7(unsigned int limit) {

	unsigned long long* prime_list = malloc(sizeof(unsigned long long) * limit);
	unsigned long long* multiple_list = malloc(sizeof(unsigned long long) * limit);

	*prime_list = 5;
	*multiple_list = 25;

	int pas = 2;
	unsigned long ptr, found = 1;
	unsigned long long number = 7;

	while (found < limit)
	{
		ptr = 0;
		for (int i = *(prime_list + ptr); number != *(multiple_list + ptr) && i*i < number; i = *(prime_list + ptr++)) {
			if (*(multiple_list + ptr) < number)
				*(multiple_list + ptr) += *(prime_list + ptr) * 2;
		}
		if (number != *(multiple_list + ptr)) {
			prime_list[found] = number;
			multiple_list[found++] = number * number;
		}
		number += (pas = 6 - pas);
	}

	free(prime_list);
	free(multiple_list);
}




void print_until(int number) {
	int line = 0;
	for (int i = 0; i < number; i++) {
		if (premier_option4(i)) {
			line++;
			printf("%d\n", i);
			if (line % 25 == 0 && line != 0) {
				printf("Appuyer sur une touche pour afficher les 25 premiers suivants");
				getchar();
			}
		}
	}
}

void search_for(int limit) {
	int line = 0, number = 0;
	while (line <= limit)
	{
		number++;
		if (premier_option4(number)) {
			line++;
			printf("%d\n", number);
			if (line % 25 == 0 && line != 0) {
				printf("Appuyer sur une touche pour afficher les 25 premiers suivants");
				getchar();
			}
		}
	}
}