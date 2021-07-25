#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct person {
	char name[10];
	int age;
	char hobby[10];
};
void main() 
{
	FILE *fp = fopen("personal.txt", "r");
	if (fp == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}
	FILE *fp1 = fopen("age.txt", "w");
	if (fp1 == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}

	FILE *fp2 = fopen("hobby.txt", "w");
	if (fp2 == NULL) 
	{
		printf("File could not be founded");
		exit(11);
	}
	struct person p[100];
	int index = 0;

	while (!feof(fp)) 
	{
	
		fscanf(fp, "%s", p[index].name);
		fscanf(fp, "%d", &p[index].age);
		fscanf(fp, "%s", p[index].hobby);
		
		fprintf(fp1, "%-8s %-8d\n", p[index].name, p[index].age);
		fprintf(fp2, "%-8s %-8s\n", p[index].name, p[index].hobby);
		index++;
	}

	fclose(fp);
	fclose(fp1);
	fclose(fp2);
}
