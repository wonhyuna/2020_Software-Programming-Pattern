#include <stdio.h>

void main() 
{
	char ch;
	printf("ch : ");
	scanf_s("%c", &ch);

	int mask = 0x80;

	for (int i = 0; i < 8; i++) 
	{
		if (ch & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask = mask >> 1;
	}
}