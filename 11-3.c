#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Personal 
{
	char name[15];
	int age;
	char hobby[15];
};

void main() 
{
	FILE *personal; 
	FILE *age; 
	FILE *hobby; 
	struct Personal info[100], temp;
	int i = 0, j = 0; 
	int cnt = 0;
	int index = 0;

	personal = fopen("personal.txt", "r"); 
	age = fopen("age.txt", "w"); 
	hobby = fopen("hobby.txt", "w"); 

	if (personal == NULL || age == NULL || hobby == NULL) 
	{		
		printf("File could not be opened\n");
		exit(1);
	}

	while (fscanf(personal, "%s %d %s", info[i].name, &info[i].age, info[i].hobby) != EOF) 
	{ 
		i++; 
		cnt++; 
	}

	for (i = 0; i < cnt; i++) 
	{
		for (j = i; j < cnt; j++) 
		{
			if (info[i].age == info[j].age && i != j) 
			{
				index++;
				temp = info[index];
				info[index] = info[j];
				info[j] = temp;
			}
		}
		i = index++;
	}

	for (i = 0; i < cnt; i++)
	{
		fprintf(age, "%s %d %s\n", info[i].name, info[i].age, info[i].hobby);
	}

	index = 0; 
	for (i = 0; i < cnt; i++) 
	{
		for (j = i; j < cnt; j++) 
		{
			if (strcmp(info[i].hobby, info[j].hobby) == 0 && i != j) 
			{ 
				index++;
				temp = info[index];
				info[index] = info[j];
				info[j] = temp;
			}
		}
		i = index++;
	}

	for (i = 0; i < cnt; i++)
	{
		fprintf(hobby, "%s %d %s\n", info[i].name, info[i].age, info[i].hobby);
	}

	fclose(personal); 
	fclose(age); 
	fclose(hobby); 
}