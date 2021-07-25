#include <stdio.h>

void main()
{
	int i, j = 0, m, n, dec, num, bin[32];
	char c_hex[] = "0123456789ABCDEF";
	char hex[10] = {0};

	printf("Dec: ");
	scanf_s("%d", &dec);
	printf("Dec: %d ", dec);
	num = dec;
	
	while (1)
	{
		m = dec / 2;              
		n = dec - (m * 2);  
		bin[j++] = n;

		if (m <= 0)
			break;
		dec = m;
	}
	printf("Bin: ");
	for (i = j - 1; i >= 0; i--)
	{
		printf("%d", bin[i]);
	}

	while (1)
	{
		m = num / 16;         
		n = num - (m * 16);   
		hex[j++] = c_hex[n];

		if (m <= 0)
			break;
		num = m;
	}
	printf(" Hex: ");
	for (i = j - 1; i >= 0; i--)
	{
		printf("%c", hex[i]);
	}
	printf("\n");
}