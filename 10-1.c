#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CAR {
	char name[20];
	int year;
}car[2];


int main(void)
{
	FILE *cfPtr;		
	struct CAR car[2] = { {"Avante", 2007}, {"Sonata", 2008} };
	
	if ((cfPtr = fopen("cars.txt", "w")) == NULL)
	{
		puts("File could not be opened");
		exit(1);
	}
	
	for (int i = 0; i < 2; i++)
	{
		fprintf(cfPtr, "%s %d\n", car[i].name, car[i].year);
	}
	fclose(cfPtr);

	if ((cfPtr = fopen("cars.txt", "r")) == NULL) {
		printf("File could not be opened");
		exit(1);
	}


	for (int i = 0; i < 2; i++)
	{
		printf("%s   %d\n", car[i].name, car[i].year);
	}

	fclose(cfPtr);	

	return 0;
}