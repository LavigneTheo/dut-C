#include "Time_diff.h"

#define GROUP_PER 50

void perf_test_1(unsigned long number) {

	int array_size = number / GROUP_PER + 1;
	int* data = calloc(array_size, sizeof(int));

	//Pointeur des fonctions à éxécuter
	Boolean(*func_test[7])(unsigned long) = {
		&premier_option0,
		&premier_option1,
		&premier_option2,
		&premier_option3,
		&premier_option4,
		&premier_option5,
		&premier_option6,
	};

	//Chemin vers les fichiers on sont sauvegardé les données
	const char *paths_test_1[7];
	paths_test_1[0] = "./src/data/test_1/opt0.txt";
	paths_test_1[1] = "./src/data/test_1/opt1.txt";
	paths_test_1[2] = "./src/data/test_1/opt2.txt";
	paths_test_1[3] = "./src/data/test_1/opt3.txt";
	paths_test_1[4] = "./src/data/test_1/opt4.txt";
	paths_test_1[5] = "./src/data/test_1/opt5.txt";
	paths_test_1[6] = "./src/data/test_1/opt6.txt";

	for (int i = 0; i < 7; i++) {
		run_test(number, data, func_test[i]);
		save_data(data, paths_test_1[i], array_size);
	}

	free(data);
}

void perf_test_2(unsigned long limit) {
	int array_size = limit / GROUP_PER + 1;
	int* data = calloc(array_size, sizeof(int));

	Boolean(*func_test[3])(unsigned long) = {
		&premier_option2,
		&premier_option5,
		&premier_option6,
	};

	const char *paths_test_1[4];
	paths_test_1[0] = "./src/data/test_2/opt2.txt";
	paths_test_1[1] = "./src/data/test_2/opt5.txt";
	paths_test_1[2] = "./src/data/test_2/opt6.txt";
	paths_test_1[3] = "./src/data/test_2/opt7.txt";

	for (int i = 0; i < 3; i++) {
		run_test(limit, data, func_test[i]);
		save_data(data, paths_test_1[i], array_size);
	}

	struct timeb start, end;
	int diff, itrator_data = 0;
	for (unsigned long i = GROUP_PER; i < limit; i += GROUP_PER) {
		ftime(&start);
		premier_option7(i);
		ftime(&end);
		diff = (int)(1000.0 * (end.time - start.time)
			+ (end.millitm - start.millitm));
		*(data + itrator_data++) = diff;
	}
	save_data(data, paths_test_1[3], array_size);


	free(data);

}



void save_data(const int* data, const char* file_name, const int array_size) {
	FILE* f = NULL;
	fopen_s(&f, file_name, "w");

	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	for (int i = 0; i < array_size - 2; i++)
		fprintf(f, "%d %d\n", i, *(data + i));

	fclose(f);
}

void run_test(const unsigned int limit, int* data, Boolean(*function_premier)(unsigned long)) {
	struct timeb start, end;
	int diff;
	ftime(&start);
	unsigned int found = 0, itrator_data = 0, next_stage = GROUP_PER;
	unsigned long number = 0;

	while (found < limit) {
		number++;
		if (function_premier(number)) {
			found++;
		}


		if (found == next_stage) {
			ftime(&end);
			next_stage += GROUP_PER;
			printf("%d\n", found);
			*(data + itrator_data++) = get_diff(start, end);
			found = 0;
			number = 0;
			ftime(&start);
		}
	}
}

int get_diff(struct timeb start, struct timeb end) {
	return (int)
		(1000.0 * (end.time - start.time) +
		(end.millitm - start.millitm));
}


