#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *readPtr;
	int num, n;
	double sum, aver;

	readPtr = fopen("number.txt", "r");
	if (readPtr == NULL)
	{
		puts("File could not be opened");
		exit(1);
	}
	while (!feof(readPtr))
	{

		fscanf(readPtr, "%d", &n);
		sum = 0;
		if (!feof(readPtr))
		{
			for (int i = 1; i < n + 1; i++)
			{
				fscanf(readPtr, "%d", &num);
				sum = sum + num;
			}
		}
		else
			break;
		aver = sum / n;
		printf("average: %lf\n", aver);

	}
	fclose(readPtr);

}
