#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
	char name[20];
	char name1[20];
	int num;
	double num1;
	char num2[20];
}emp[5];

void main()
{
	FILE *cfPtr = fopen("employee.dat", "w");
	FILE *readPtr = fopen("employee.dat", "r");
	FILE *writePtr = fopen("employee.bak", "w");
	char emp[5][200] = { "Anthony  A.J.  10031  7.82  12/18/62", "Burrows  W.K.  10067  9.14  6/9/63",
	"Fain  B.D.  10083  8.79  5/18/59", "Janney  P.  10095  10.57  9/28/62", "Smith  G.J.  10105  8.50  12/20/61" };
	if (cfPtr == NULL)
	{
		puts("File could not be opened");
		exit(1);
	}
	for (int i = 0; i < 5; i++)
	{
		fprintf(cfPtr, "%s\n", emp[i]);
	}
	fclose(cfPtr);

	while (!feof(readPtr))
	{
		fgets(emp, 5, readPtr);
		fputs(emp, writePtr);
	}
	fclose(readPtr);
	fclose(writePtr);

}