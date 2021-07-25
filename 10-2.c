#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CAR {
	char name[20];
	int year;
	double price;
}car[4];


int main(void)
{
	FILE *cfPtr;
	struct CAR car[4] = { {"Avante", 2007, 13000.00}, {"Sonata", 2008, 18000.00}, {"SM7", 2009, 22000.00}, {"Equus", 2010, 35000.00} };

	if ((cfPtr = fopen("car.txt", "w")) == NULL)
	{
		puts("File could not be opened");
		exit(1);
	}

	fprintf(cfPtr, "|Name\t|Year\t|Price\t|\n");
	fprintf(cfPtr, "---------------------------\n");
	for (int i = 0; i < 4; i++)
	{
		fprintf(cfPtr, "|%s\t|%d\t|%.2lf|\n", car[i].name, car[i].year, car[i].price);
	}
	fclose(cfPtr);

	if ((cfPtr = fopen("car.txt", "r")) == NULL) {
		printf("File could not be opened");
		exit(1);
	}


	printf("|Name\t|Year\t|Price\t|\n");
	printf("---------------------------\n");
	for (int i = 0; i < 4; i++)
	{
		printf("|%s\t|%d\t|%.2lf|\n", car[i].name, car[i].year, car[i].price);
	}

	fclose(cfPtr);

	return 0;
}