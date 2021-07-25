#include <stdio.h>

int Days(struct Date cal);

struct Date {
	int month;
	int day;
	int year;
};

int Days(struct Date cal) {
	int sum;
	sum = (cal.year - 2000) * 360 + (cal.month - 1) * 30 + (cal.day - 1);
	return sum;
}

void main() {
	struct Date d1;
	int result;

	printf("write the month: ");
	scanf_s("%d", &d1.month);

	printf("write the day: ");
	scanf_s("%d", &d1.day);

	printf("write the year: ");
	scanf_s("%d", &d1.year);
	
	result = Days(d1);
	printf("result: %d",result);
}