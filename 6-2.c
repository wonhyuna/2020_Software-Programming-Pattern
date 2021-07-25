#include<stdio.h>
#include <string.h>
struct people {
	char name[20];
	int age;
	char hobby[20];
}index[5];
int main()
{
	struct people index[5] = { {"Kim", 39, "Tennis"}, {"Ko", 15, "Soccer"}, {"Lee", 17, "Soccer"}, {"Oh", 21, "Tennis"}, {"Park", 10, "Tennis"} };
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(index[i].name, "Lee") == 0)
		{
			printf("Lee's information / age: %d, hobby: %s \n", index[i].age, index[i].hobby);
		}
		else if (strcmp(index[i].name, "Park") == 0)
		{
			printf("Park's information / age: %d, hobby: %s \n", index[i].age, index[i].hobby);
		}

	}
}