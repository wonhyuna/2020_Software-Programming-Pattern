#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

FILE *file1, *file2, *file3, *file4;
void XSpace(char *sentence);
void Encryption(int len, int length, int encryption[][20], char input[]);
void Decryption(int KEY, int decryption[], char input[], int encryption[]);

int main()
{
	file1 = fopen("original1.txt", "r");
	file2 = fopen("cypher1.txt", "w");
	file3 = fopen("decrypted1.txt", "w");
	file4 = fopen("cypher1.txt", "r");

	int key[20], n;
	char keyword[20], str[20], temp;
	char sentence[100] = {NULL, };
	int length, i, j;
	fgets(sentence, sizeof(sentence), file1);

	printf("Write the keyword: ");
	scanf("%s", keyword);
	length = strlen(keyword) - 1;
	strcpy(str, keyword);

	//length-> 5
	//str-> ZEBRAS
	//keyword-> ABERSZ    
	//key-> 6 3 2 4 1 5
	//sentence-> WE ARE DISCOVERED FLEE AT ONCE

	for (j = 0; j < length; j++)
	{
		for (i = 0; i < length - j; i++)
		{
			if (keyword[i] > keyword[i + 1])
			{
				temp = keyword[i];
				keyword[i] = keyword[i + 1];
				keyword[i + 1] = temp;
			}
		}
	}
	for (int k = 0; k < length + 1; k++)
	{
		for (n = 0; n < length + 1; n++)
		{
			if (keyword[k] == str[n])
			{
				key[n] = k+1;
			}
		}
	}
	XSpace(sentence);

	//for (i = 0; i < strlen(sentence); i++)
	//{
		//printf("%c", sentence[i]);
	//}
	int len = strlen(sentence);
	char encryption[20][20];
	Encryption(len, length, encryption, sentence);

}

void XSpace(char *r_sentence)
{
	char *sen = r_sentence;

	while (*r_sentence != '\0')
	{
		if (*r_sentence != ' ')
		{
			if (sen != r_sentence)
				*sen = *r_sentence;
			sen++;
		}
		r_sentence++;
	}
	*sen= 0;
}

void Encryption(int len, int length, int encryption[][20], char sentence[])
{
	for (int i = 0; i < len; i++)
	{
		
	}
}

void Decryption(int KEY, int decryption[], char input[], int encryption[])
{

}