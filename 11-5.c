#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double W = 0; 
double L = 0; 
double C = 0; 
int no = 0; 

void percentage(FILE*, int); 
void main() 
{
	FILE *fp; 

	fp = fopen("vote.txt", "r"); 
	if (fp == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	printf("Sample every all row\n");
	percentage(fp, 1); 

	fseek(fp, 0, SEEK_SET); 

	printf("Sample every third row\n");
	percentage(fp, 3); 

	fseek(fp, 0, SEEK_SET); 

	printf("Sample every tenth row\n");
	percentage(fp, 10); 
	fclose(fp); 
}
void percentage(FILE *fp, int num) 
{
	int age = 0; 
	int line = 0; 
	int cnt = 0; 
	char region[15]; 
	char candidate[15]; 

	W = 0; 
	L = 0; 
	C = 0; 
	while (fscanf(fp, "%s %d %s", region, &age, candidate) == 3) 
	{ 
		line++; 
		if (line % num == 0) 
		{ 
			if (strcmp(candidate, "Washington") == 0) 
				W++;
			else if (strcmp(candidate, "Lincoln") == 0) 
				L++;
			else if (strcmp(candidate, "Roosevelt") == 0) 
				C++;
			else 
				no++;
			cnt++; 
		}
	}

	W = (W / cnt) * 100;
	L = (L / cnt) * 100;
	C = (C / cnt) * 100;

	printf("Washington : %0.1f\nLincoln : %0.1f\nRoosevelt : %0.1f\n\n", W, L, C);
}