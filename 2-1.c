#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct DayDay {
	char month[20];
	char day[20];
	char year[20];
};

int main() {
	struct DayDay d1;

	scanf_s("%s", d1.year);
	scanf_s("%s", d1.month);
	scanf_s("%s", d1.day);

	printf("연도: %s\n", d1.year);
	printf("월: %s\n", d1.month);
	printf("일: %s\n", d1.day);

	return 0;

}
