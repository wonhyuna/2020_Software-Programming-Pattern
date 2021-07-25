#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person {
	char name[10];
	int age;
	double salary;

};
void main() 
{
	FILE *fp = fopen("salary_v1.txt", "r");
	if (fp == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}
	FILE *fp1 = fopen("salary_v2.txt", "w");
	if (fp1 == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}

	FILE *fp2 = fopen("salary_v3.txt", "w");
	if (fp2 == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}
	struct person p[100];
	struct person temp[100];
	int index = 0;

	while (!feof(fp)) 
	{
		fscanf(fp, "%s", p[index].name);
		fscanf(fp, "%d", &p[index].age);
		fscanf(fp, "%lf", &p[index].salary);
		strcpy(temp[index].name, p[index].name);
		temp[index].age = p[index].age;
		temp[index].salary = p[index].salary;
		index++;
	}
	
	for (int i = 0; i < index; i++) 
	{
		if (40 <= p[i].age&&p[i].age <= 49)
			p[i].salary = p[i].salary*1.1;
		fprintf(fp1, "%-8s %-8d %-8.1lf\n", p[i].name, p[i].age, p[i].salary);
	}
	fclose(fp1);
	fp1 = fopen("salary_v2.txt", "r");
	if (fp1 == NULL) 
	{
		printf("File could not be founded");
		exit(1);
	}
	index = 0;
	
	while (!feof(fp1)) 
	{
		fscanf(fp1, "%s", p[index].name);
		fscanf(fp1, "%d", &p[index].age);
		fscanf(fp1, "%lf", &p[index].salary);
		index++;
	}
	index--;

	for (int i = 0; i < index; i++) 
	{
		if (30 <= p[i].age&&p[i].age <= 39)
			p[i].salary = p[i].salary*1.2;
		fprintf(fp2, "%-8s %-8d %-8.1lf\n", p[i].name, p[i].age, p[i].salary);
	}

	fclose(fp);
	fclose(fp1);
	fclose(fp2);

	for (int i = 0; i < index; i++) 
	{
		printf("%-8s  %-8d  %-8.1f -> %-8.1lf\n", p[i].name, p[i].age, temp[i].salary, p[i].salary);
	}
}
