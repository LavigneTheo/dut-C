#include <stdio.h>
#include "Exercice1.h"
#include "Exercice2.h"
#include "Exercice3.h"

void main()
{
	/*int* arr = calloc(sizeof(int), 26);
	int a, b;
	get_info(get_string_v3(), arr, &a, &b);

	for (int i = 0; i < 26; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d, ", a);
	printf("%d, ", b);*/

	int* arr = get_info_2(get_string_v3());
	for (int i = 0; i < 28; i++)
		printf("%d, ", arr[i]);

	getchar();

}

