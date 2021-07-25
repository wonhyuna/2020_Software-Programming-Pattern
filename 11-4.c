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
		printf("File could not be opened");
		exit(1);
	}
	FILE *fp1 = fopen("output.txt", "w");
	if (fp1 == NULL) 
	{
		printf("File could not be opened");
		exit(1);
	}
	struct person p[100];
	int index = 0;
	
	while (!feof(fp)) 
	{
		fscanf(fp, "%s", p[index].name);
		fscanf(fp, "%d", &p[index].age);
		fscanf(fp, "%s", p[index].hobby);
		index++;
	}
	
	fprintf(fp1, "Age from 10 to 19\n-------------------\n");
	for (int i = 0; i < index; i++) 
	{
		if (10 <= p[i].age && 19 >= p[i].age)
			fprintf(fp1, "%-8s%-8d%-8s\n", p[i].name, p[i].age, p[i].hobby);
	}
	fprintf(fp1, "\nAge from 20 to 29\n-------------------\n");
	for (int i = 0; i < index; i++) 
	{
		if (20 <= p[i].age&& p[i].age <= 29)
			fprintf(fp1, "%-8s%-8d%-8s\n", p[i].name, p[i].age, p[i].hobby);
	}
	fprintf(fp1, "\nAge from 30 to 39\n-------------------\n");
	for (int i = 0; i < index; i++) 
	{
		if (30 <= p[i].age&&p[i].age <= 39)
			fprintf(fp1, "%-8s%-8d%-8s\n", p[i].name, p[i].age, p[i].hobby);
	}
	fprintf(fp1, "\nAge from 40 to 49\n-------------------\n");
	for (int i = 0; i < index; i++) 
	{
		if (40 <= p[i].age&&p[i].age <= 49)
			fprintf(fp1, "%-8s%-8d%-8s\n", p[i].name, p[i].age, p[i].hobby);
	}
	fclose(fp);
	fclose(fp1);
}