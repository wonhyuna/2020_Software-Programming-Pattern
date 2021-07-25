#include <stdio.h>

struct Date {
	int month;
	int day;
	int year;
};

void main() {
	struct Date x, y, late;
	struct Date recent(struct Date, struct Date);

	printf("write the first date:");
	scanf_s("%d %d %d", &x.month, &x.day, &x.year);
	printf("write the second date:");
	scanf_s("%d %d %d", &y.month, &y.day, &y.year);

	if (x.month <= 0 || x.day <= 0 || x.year <= 0 || y.month <= 0 || y.day <= 0 || y.year <= 0) {
		printf("Wrong input");
	}
	else if (x.month == y.month && x.day == y.day && x.year == y.year) {
		printf("Same Date");
	}
	else {
		late = recent(x, y);
		printf("The recent date: %d/%d/%d", late.month, late.day, late.year);
	}
}

struct Date recent(struct Date n, struct Date m) {
	if (n.year == m.year)
	{
		if (n.month == m.month)
		{
			if (n.day == m.day)
			{
				
			}
			else if (n.day > m.day)
			{
				return n;
			}
			else {
				return m;
			}
		}
		else if (n.month > m.month)
		{
			return n;
		}
		else
		{
			return m;
		}
	}

	else if (n.year > m.year)
	{
		return n;
	}

	else
	{
		return m;
	}
}
