#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


void Encryption(int KEY, int encryption[], char input[]);
void Decryption(int KEY, int decryption[], char input[], int encryption[]);

FILE *file1, *file2, *file3, *file4;

int main(void)
{
	file1 = fopen("original.txt", "r");
	file2 = fopen("cypher.txt", "w");
	file3 = fopen("decrypted.txt", "w");
	file4 = fopen("cypher.txt", "r");

	char input[1000];
	char encry[1000];
	int KEY;
	int encryption[1000] = { NULL, };
	int decryption[1000] = { NULL, };

	fgets(input, sizeof(input), file1);

	fgets(encryption, sizeof(encryption), file4);

	printf("Write the key (1~25) : ");
	scanf_s("%d", &KEY);

	Encryption(KEY, encryption, input);
	//fwrite(encryption, strlen(encryption), 1000, file2);
	//fputs(encryption, file2);
	printf("\n");

	Decryption(KEY, decryption, input, encryption);
	//fwrite(decryption, strlen(decryption), 1000, file3);
	printf("\n");
	
	fclose(file1);
	return 0;
}



void Encryption(int KEY, int encryption[], char input[]) 
{
	int i;
	for (i = 0; i < strlen(input); i++)
	{
		encryption[i] = (input[i] + KEY);
		if (input[i] == 32)
			encryption[i] = input[i];
		else if (encryption[i] > 122)
			encryption[i] = encryption[i] - 26;

		fprintf(file2, "%c", encryption[i]);
		
	}

}

void Decryption(int KEY, int decryption[], char input[], int encryption[])
{
	//fgets(encry, sizeof(encry), file2);

	int i;
	for (i = 0; NULL != encryption[i]; i++)
	{
		decryption[i] = (encryption[i] - KEY);
		if (encryption[i] == 32)
			decryption[i] = encryption[i];
		else if (decryption[i] < 97)
			decryption[i] = encryption[i] + 26 - KEY;

		fprintf(file3, "%c", decryption[i]);
	}

}