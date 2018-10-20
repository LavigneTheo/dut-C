#include "Time_diff.h"



#define GROUP_PER 500

void perf_test_1(unsigned long number) {

	int array_size = number / GROUP_PER + 1;
	int* data = calloc(array_size, sizeof(int));

	Boolean(*func_test[8])(unsigned long) = {
		&premier_option0,
		&premier_option1,
		&premier_option2,
		&premier_option3,
		&premier_option4,
		&premier_option5,
		&premier_option6,
		&premier_option7,
	};

	const char *paths_test_1[8];
	paths_test_1[0] = "./src/data/test_1/opt0.txt";
	paths_test_1[1] = "./src/data/test_1/opt1.txt";
	paths_test_1[2] = "./src/data/test_1/opt2.txt";
	paths_test_1[3] = "./src/data/test_1/opt3.txt";
	paths_test_1[4] = "./src/data/test_1/opt4.txt";
	paths_test_1[5] = "./src/data/test_1/opt5.txt";
	paths_test_1[6] = "./src/data/test_1/opt6.txt";
	paths_test_1[7] = "./src/data/test_1/opt7.txt";

	for (int i = 0; i < 8; i++) {
		run_test1(number, data, func_test[i]);
		save_data(data, paths_test_1[i], array_size);
	}

	const char *paths_test_2[8];
	paths_test_2[0] = "./src/data/test_2/opt0.txt";
	paths_test_2[1] = "./src/data/test_2/opt1.txt";
	paths_test_2[2] = "./src/data/test_2/opt2.txt";
	paths_test_2[3] = "./src/data/test_2/opt3.txt";
	paths_test_2[4] = "./src/data/test_2/opt4.txt";
	paths_test_2[5] = "./src/data/test_2/opt5.txt";
	paths_test_2[6] = "./src/data/test_2/opt6.txt";
	paths_test_2[7] = "./src/data/test_2/opt7.txt";

	for (int i = 0; i < 8; i++) {
		run_test2(number, data, func_test[i]);
		save_data(data, paths_test_2[i], array_size);
	}

	free(data);
}

void perf_test_2(unsigned long limit) {
	int array_size = limit / GROUP_PER + 1;
	int* data = calloc(array_size, sizeof(int));

	Boolean(*func_test[4])(unsigned long) = {
		&premier_option2,
		&premier_option6,
		&premier_option7,
	};

	const char *paths_test_1[5];
	paths_test_1[0] = "./src/data/test_3/opt2.txt";
	paths_test_1[1] = "./src/data/test_3/opt6.txt";
	paths_test_1[2] = "./src/data/test_3/opt7.txt";
	paths_test_1[3] = "./src/data/test_3/opt8.txt";

	for (int i = 0; i < 3; i++) {
		run_test2(limit, data, func_test[i]);
		save_data(data, paths_test_1[i], array_size);
	}

	struct timeb start, end;
	int diff, itrator_data = 0;
	for (unsigned long i = GROUP_PER; i < limit; i += GROUP_PER) {
		ftime(&start);
		premier_option8(i);
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

void run_test2(const unsigned long number, int* data, Boolean(*function_premier)(unsigned long)) {
	struct timeb start, end;
	int diff;
	ftime(&start);
	int found = 0, iterator = 0, itrator_data = 0,  stage = 1;

	while (found < number) {
		iterator++;
		if (function_premier(iterator)) {
			found++;
		}


		if (found % (GROUP_PER * stage) == 0 && found != 0) {
			ftime(&end);
			stage++;
			printf("%d\n", found);
			diff = (int)(1000.0 * (end.time - start.time)
				+ (end.millitm - start.millitm));
			*(data + itrator_data++) = diff;
			found = 0;
			iterator = 0;
			ftime(&start);
		}
	}
}


void run_test1(const unsigned long number, int* data, Boolean(*function_premier)(unsigned long)) {
	struct timeb start, end;
	int diff;
	ftime(&start);
	int found = 0, iterator = 0, itrator_data = 0;
	Boolean saved = FALSE;
	
	while (found < number) {
		iterator++;
		if (function_premier(iterator)) {
			found++;
			saved = FALSE;
		}


		if (found % GROUP_PER == 0 && !saved) {
			saved = TRUE;
			
			ftime(&end);
			diff = (int)(1000.0 * (end.time - start.time)
				+ (end.millitm - start.millitm));
			*(data + itrator_data++) = diff;
			printf("Found : %d - time : %d\n", found, diff);
			ftime(&start);
		}
	}
}