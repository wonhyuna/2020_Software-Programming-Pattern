#include <stdio.h>

struct Array{
	char name[20];
	int age;
	char hobby[20];
};

struct index {
	char *name_ptr;
	int number;
};

int main() {
	struct Array arr[5] = { {"Kim", 39, "Tennis"}, {"Ko", 15, "Soccer"}, {"Lee", 17, "Soccer"}, {"Oh", 21, "Tennis"}, {"Park", 10, "Tennis"} };
	struct index in[5] = { {&arr[0].name, 0}, {&arr[1].name, 1}, {&arr[2].name, 2},{&arr[3].name, 3}, {&arr[4].name, 4} };

	printf("Lee's information  age : %d, hobby : %s\n", arr[in[2].number].age, arr[in[2].number].hobby);
	printf("Park's information  age : %d, hobby : %s\n", arr[in[4].number].age, arr[in[4].number].hobby);
}