#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100;
#define MAX_AFFILICATION_LENGTH 100;
#define MAX_ARRAY_SIZE 100;

struct student
{
	char name[100];
	int age;
	char affilication[100];
};


int main()
{
	struct student arr[4];
	int idx = 0;

	FILE *myFile;
	myFile = fopen("student.txt", "r");

	for (int i = 0; i < 4; i++)
	{
		fscanf(myFile, "%s %d %s", &arr[i].name, &arr[i].age, &arr[i].affilication);
		//idx++;
	}


	for (int i = 0; i < 4; i++)
	{
		printf("%s %d %s\n", arr[i].name, arr[i].age, arr[i].affilication);
	}

	fclose(myFile);
	return 1;


}

