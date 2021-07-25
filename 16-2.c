#include <stdio.h>

int counts(int a, int b)
{
	int c = a ^ b;

	int count = 0;
	while (c != 0)
	{
		c = c & (c - 1);
		count++;
	}
	return count;
}



int main()
{
	unsigned char a, b;
	int result;
	printf("write the a and b: ");
	scanf_s("%c, %c", &a, &b);
	result = counts(a, b);

	printf("%d", result);
	return 0;
}