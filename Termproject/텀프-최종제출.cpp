#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int tag;
    char date[20];
    char fee_paid[10];
    char name[20];
    int age;
    char university[40];
    char job[20];
};
struct NODE {
    struct NODE* next;
    int tag;
    char date[20];
    char fee_paid[10];
    char name[20];
    int age;
    char university[40];
    char job[20];
};

void File_Line_input(char File_Line[][100], struct person* input_struct)//data_store
{
    char inf[7][40];
    int count = 0;
    int chn = 0;
    int i, j;

    for (j = 0; j < 30; j++)
    {
        for (i = 0; i < strlen(File_Line[j]) + 1; i++)
        {
            if (File_Line[j][i] == 47)
            {
                inf[count][chn] = 0;
                count++;
                chn = 0;
            }
            else if (File_Line[j][i] != 47)
            {
                inf[count][chn] = File_Line[j][i];
                chn++;
            }
            else if (File_Line[j][i] == 0)
            {
                inf[count][chn] = 0;
            }
        }
        input_struct[j].tag = atoi(inf[0]);
        strcpy(input_struct[j].date, inf[1]);
        strcpy(input_struct[j].fee_paid, inf[2]);
        strcpy(input_struct[j].name, inf[3]);
        input_struct[j].age = atoi(inf[4]);
        strcpy(input_struct[j].university, inf[5]);
        strcpy(input_struct[j].job, inf[6]);

        count = 0;
        chn = 0;
    }
}
void add_node(struct NODE* target, int tag, char date[], char fee_paid[], char name[], int age, char uni[], char job[])
{
    //Add node function
    struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->next = target->next;

    newNode->tag = tag;
    strcpy(newNode->date, date);
    strcpy(newNode->fee_paid, fee_paid);
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->university, uni);
    strcpy(newNode->job, job);

    target->next = newNode;
}
void remove_node(char name[], struct NODE* target, struct NODE* oldnode, int* num)
{
    //Remove node function
    int i, j, z;
    int check = 0;
    int count = 0;
    for (z = 0; z < strlen(target->name); z++)
    {
        if (target->name[z] == name[check])
        {
            if (check == strlen(name) - 1)
            {
                if (target->name[z + 1] == name[check + 1])
                {
                    count++;
                    printf("\nDeleted Node : %s", target->name);
                    oldnode->next = target->next;
                    *num = 100;
                    free(target);
                    break;
                }
            }
            else
            {
                check++;
            }
        }
        else
        {
            check = 0;
        }
    }
    check = 0;
}

void setup(char File_Line[][100], struct person* p1, struct NODE* address)
{
    FILE* fp1 = fopen("registraion_data.txt", "r");
    int i;
    for (i = 0; i < 30; i++)
    {
        fgets(File_Line[i], sizeof(File_Line[i]), fp1);//save 30 lines of content in a file
    }
    fclose(fp1);

    File_Line_input(File_Line, p1); //process dataand store it in a struct array
    int z;
    for (z = 0; z < 30; z++) //store data in linked list
    {
        add_node(address, p1[z].tag, p1[z].date, p1[z].fee_paid, p1[z].name, p1[z].age, p1[z].university, p1[z].job);
        address = address->next;
    }
}
void search_name(struct person* P1)
{
    char name[31];
    printf("Search name :");
    scanf("%[^\n]", name); //read name 
    printf("\nstruct name search");
    printf("\n");

    int i, j, z;
    int check = 0;
    int count = 0;
    for (j = 0; j < 30; j++)  //Search data of name that read
    {
        for (z = 0; z < strlen((P1 + j)->name); z++)
        {
            if ((P1 + j)->name[z] == name[check])
            {
                if (check == strlen(name) - 1)
                {
                    if ((P1 + j)->name[z + 1] == name[check + 1]) //if found, print all information about the persons
                    {
                        count++;
                        printf("[%d] %d %s %s %s %d %s %s", count, (P1 + j)->tag, (P1 + j)->name, (P1 + j)->date, (P1 + j)->fee_paid, (P1 + j)->age, (P1 + j)->university, (P1 + j)->job);
                        break;
                    }
                }
                else
                {
                    check++;
                }
            }
            else
            {
                check = 0;
            }
        }
        check = 0;
    }
}
void search_name2(struct NODE* target)
{
    char name[31];
    printf("\nSearch name :");
    scanf(" %[^\n]", name);  //read name 
    printf("\nlinked list name search");
    printf("\n");

    int i, j, z;
    int check = 0;
    int count = 0;
    printf("\n");
    while (target != NULL)
    {
        for (z = 0; z < strlen(target->name); z++)//Search data of name that read
        {
            if (target->name[z] == name[check])
            {
                if (check == strlen(name) - 1)
                {
                    if (target->name[z + 1] == name[check + 1])//if found, print all information about the persons
                    {
                        count++;
                        printf("[%d] %d %s %s %s %d %s %s", count, target->tag, target->name, target->date, target->fee_paid, target->age, target->university, target->job);

                        break;
                    }
                }
                else
                {
                    check++;
                }
            }
            else
            {
                check = 0;
            }
        }
        check = 0;
        target = target->next;
    }
}
void search_uni(struct person* P1)
{
    char uni[30];
    printf("\nSearch university's name :");
    scanf(" %[^\n]", uni); //read university

    int i, j, z;
    int check = 0;
    int count = 0;
    printf("\n");
    for (j = 0; j < 30; j++)
    {
        
        for (z = 0; z < strlen((P1 + j)->university); z++)//Search data of university that read
        {
            if ((P1 + j)->university[z] == uni[check])
            {
                if (check == strlen(uni) - 1)//if found, print all information about the persons
                {
                    count++;
                    printf("[%d] %d %s %s %s %d %s %s", count, (P1 + j)->tag, (P1 + j)->name, (P1 + j)->date, (P1 + j)->fee_paid, (P1 + j)->age, (P1 + j)->university, (P1 + j)->job);
                    break;
                }
                else
                {
                    check++;
                }
            }
            else
            {
                check = 0;
            }
        }
        check = 0;
    }
}
void search_uni2(struct NODE* target)
{
    char uni[30];
    printf("\n\nSearch university's name :");
    scanf(" %[^\n]", uni); //read university

    int i, j, z;
    int check = 0;
    int count = 0;
    printf("\n");
    while (target != NULL)
    {
        
        for (z = 0; z < strlen(target->university); z++)//Search data of university that read
        {
            if (target->university[z] == uni[check])
            {
                if (check == strlen(uni) - 1)//if found, print all information about the persons
                {
                    count++;
                    printf("[%d] %d %s %s %s %d %s %s", count, target->tag, target->name, target->date, target->fee_paid, target->age, target->university, target->job);
                    break;
                }
                else
                {
                    check++;
                }
            }
            else
            {
                check = 0;
            }
        }
        check = 0;
        target = target->next;
    }
}
void Sort_array_tag(char File_Line[][100], struct person* sort_tag, char File_Line1[][100])
{
    char num1[30][3];
    int num[30];
    int i, j;

    for (i = 0; i < 30; i++)
    {
        strcpy(File_Line1[i], File_Line[i]); //Store File_line contents in File_Line1
    }

    for (i = 0; i < 30; i++)//Extracts person data from the line and store data
    {
        for (j = 0; j < 3; j++)
        {
            if (File_Line[i][j] != 47)
            {
                num1[i][j] = File_Line[i][j];
            }
            else if (File_Line[i][j] == 47)
            {
                num1[i][j] = 0;
                break;
            }
        }
        num[i] = atoi(num1[i]);
    }

    int max;
    int count;
    int temp;
    char temp1[100];

    for (i = 0; i < 30; i++) //Sort by Tag Order
    {
        max = num[0];
        for (j = 0; j < 30 - i; j++)
        {
            if (num[j] >= max)
            {
                max = num[j];
                count = j;
            }
            else
            {
                continue;
            }
        }
        temp = num[j - 1];
        num[j - 1] = num[count];
        num[count] = temp;

        strcpy(temp1, File_Line1[j - 1]);
        strcpy(File_Line1[j - 1], File_Line1[count]);
        strcpy(File_Line1[count], temp1);
    }
    printf("\n");
    File_Line_input(File_Line1, sort_tag);

    printf("\n");

    for (int z = 0; z < 30; z++)
    {
        printf("[Tag:%d] %d %s %s %s %d %s %s", z + 1, sort_tag[z].tag, sort_tag[z].date, sort_tag[z].fee_paid, sort_tag[z].name, sort_tag[z].age, sort_tag[z].university, sort_tag[z].job);
    }

}
void Create_sort_list(struct person* sort_tag, struct NODE* address1, struct NODE* head1, struct NODE* curr1)
{
    int number = 0, z;
    for (z = 0; z < 30; z++)//Make linked list that sorted by tag oreder
    {
        add_node(address1, sort_tag[z].tag, sort_tag[z].date, sort_tag[z].fee_paid, sort_tag[z].name, sort_tag[z].age, sort_tag[z].university, sort_tag[z].job);
        address1 = address1->next;
    }
    printf("\nPrint tag order linked list data\n");
    number = 0;
    curr1 = head1->next;
    while (curr1 != NULL) //Print linked list data
    {
        number++;
        printf("[Tag:%d] %d %s %s %s %d %s %s", number, curr1->tag, curr1->date, curr1->fee_paid, curr1->name, curr1->age, curr1->university, curr1->job);
        curr1 = curr1->next;
    }
}
void Sort_array_age(char File_Line[][100], struct person* sort_age, struct person* p1)
{
    int i, j;
    int max;
    int count;
    int temp;
    char temp1[100];

    for (i = 0; i < 30; i++)//Sort by Age Order
    {
        max = p1[0].age;
        for (j = 0; j < 30 - i; j++)
        {
            if (p1[j].age >= max)
            {
                max = p1[j].age;
                count = j;
            }
            else
            {
                continue;
            }
        }
        temp = p1[j - 1].age;
        p1[j - 1].age = p1[count].age;
        p1[count].age = temp;
        strcpy(temp1, File_Line[j - 1]);
        strcpy(File_Line[j - 1], File_Line[count]);
        strcpy(File_Line[count], temp1);
    }

    File_Line_input(File_Line, sort_age);

    printf("\n");
    printf("\nPrint Age order struct array\n");
    for (j = 0; j < 30; j++)
    {
        printf("[Age:%d] %d-%s-%s-%s-%d-%s-%s", sort_age[j].age, sort_age[j].tag, sort_age[j].date, sort_age[j].fee_paid, sort_age[j].name, sort_age[j].age, sort_age[j].university, sort_age[j].job);
    }
}
void Write_Sorted_File(struct person* sort_tag, struct person* sort_age, char File_Line[][100], char File_Line1[][100])
{
    FILE* fp2 = fopen("Sorted data.txt", "w");
    int i, j;
    fprintf(fp2, "------------------------------------Order-Tag------------------------------------\n\n");
    for (i = 0; i < 30; i++)//Enter data sorted in the order of tag in the file
    {
        fprintf(fp2, "[%d] ", sort_tag[i].tag);
        fputs(File_Line1[i], fp2);
    }
    fprintf(fp2, "\n------------------------------------Order-Age------------------------------------\n\n");
    for (i = 0; i < 30; i++)//Enter data sorted in the order of age in the file
    {
        fprintf(fp2, "[%d] ", sort_age[i].age);
        fputs(File_Line[i], fp2);
    }
    fclose(fp2);
}
int Array_number = 0; //size of struct array//
void remove_struct(struct person* sort_tag)
{
    char remove_name[30];
    printf("\nSearch name that will be removed :");
    scanf(" %[^\n]", remove_name); //Read name that will be removed

    int i, j, z;
    int check = 0;
    int count = 0;
    int del_num;
    int num;
    int struct_num = 0;
    for (j = 0; j < 30; j++)
    {
        for (z = 0; z < strlen((sort_tag + j)->name); z++)
        {
            if ((sort_tag + j)->name[z] == remove_name[check])
            {
                if (check == strlen(remove_name) - 1)
                {
                    if ((sort_tag + j)->name[z + 1] == remove_name[check + 1])//If name found, Delete that person's data
                    {
                        del_num = j;
                        printf("\nDeleted Name : %s", (sort_tag + j)->name);
                        for (del_num = j; del_num < (sizeof(sort_tag[0]) / sizeof(sort_tag)); del_num++)
                        {
                            memcpy(&sort_tag[del_num], &sort_tag[del_num + 1], sizeof(person));
                        }
                        count++;
                        j--;
                        break;
                    }

                }
                else
                {
                    check++;
                }
            }
            else
            {
                check = 0;
            }
        }
        check = 0;
    }

    Array_number = count;

    printf("\nStruct Array (Choi's data removed)\n");
    for (j = 0; j < sizeof(sort_tag[0]) / sizeof(sort_tag) - (Array_number); j++)//Print struct array after removed
    {
        printf("[%d] %d-%s-%s-%s-%d-%s-%s", j + 1, sort_tag[j].tag, sort_tag[j].date, sort_tag[j].fee_paid, sort_tag[j].name, sort_tag[j].age, sort_tag[j].university, sort_tag[j].job);
    }
    Array_number = j - 1;
}
void remove_linkedlist(struct NODE* oldnode, struct NODE* curr1, int* id_num, struct NODE* head1)
{
    int i;
    char remove_name[30];
    printf("\nSearch name that will be removed :");
    scanf(" %[^\n]", remove_name); //Read name that will be removed

    printf("\nlinked list (Choi's data removed)");
    while (curr1 != NULL)
    {
        remove_node(remove_name, curr1, oldnode, id_num);//If name found, Delete that person's data
        if (*id_num == 100)
        {
            curr1 = oldnode->next;
        }
        else
        {
            curr1 = curr1->next;
            oldnode = oldnode->next;
        }
        *id_num = 0;
    }
    i = 0;
    printf("\n\nlinked list after removed");
    printf("\n");
    curr1 = head1->next;
    while (curr1 != NULL)//Print linked list after removed
    {
        i++;
        printf("[%d] %d %s %s %s %d %s %s", i, curr1->tag, curr1->name, curr1->date, curr1->fee_paid, curr1->age, curr1->university, curr1->job);
        curr1 = curr1->next;
    }
}
void Add_Array(struct person* sort_tag, int struct_array_num)
{
    int i, j;
    //Store new people's data
    sort_tag[struct_array_num].tag = 2;
    strcpy(sort_tag[struct_array_num].date, "2001-11-01");
    strcpy(sort_tag[struct_array_num].fee_paid, "yes");
    strcpy(sort_tag[struct_array_num].name, "beom Paik");
    sort_tag[struct_array_num].age = 21;
    strcpy(sort_tag[struct_array_num].university, "Gachon University");
    strcpy(sort_tag[struct_array_num].job, "student\n");

    for (i = 0; i <= struct_array_num; i++)//Store new data in tag order
    {
        if (sort_tag[struct_array_num].tag < sort_tag[i].tag)
        {
            sort_tag[struct_array_num + 1].tag = sort_tag[struct_array_num].tag;
            for (j = struct_array_num + 1; j >= i; j--)
            {
                memcpy(&sort_tag[j], &sort_tag[j - 1], sizeof(person));
            }
            memcpy(&sort_tag[i], &sort_tag[struct_array_num + 1], sizeof(person));

            struct_array_num++;
            break;
        }
    }
    printf("\n\nStruct Array after Add \n");//Print struct array after add new data
    for (j = 0; j <= struct_array_num; j++)
    {
        printf("[%d] %d-%s-%s-%s-%d-%s-%s", j + 1, sort_tag[j].tag, sort_tag[j].date, sort_tag[j].fee_paid, sort_tag[j].name, sort_tag[j].age, sort_tag[j].university, sort_tag[j].job);
    }
}
void Add_linked(struct person* sort_tag, struct NODE* oldnode, struct NODE* head1, struct NODE* curr1)
{
    int i;
    //Store new people's data
    sort_tag[30].tag = 2;
    strcpy(sort_tag[30].date, "2001-11-01");
    strcpy(sort_tag[30].fee_paid, "yes");
    strcpy(sort_tag[30].name, "beom Paik");
    sort_tag[30].age = 21;
    strcpy(sort_tag[30].university, "Gachon University");
    strcpy(sort_tag[30].job, "student");

    oldnode = head1;
    curr1 = head1->next;
    i = 0;
    while (curr1 != NULL)
    {
        i++;
        if (sort_tag[30].tag < curr1->tag) // Store new data in tag order
        {
            add_node(oldnode, sort_tag[30].tag, sort_tag[30].date, sort_tag[30].fee_paid, sort_tag[30].name, sort_tag[30].age, sort_tag[30].university, sort_tag[30].job);
            break;
        }
        else
        {
            curr1 = curr1->next;
            oldnode = oldnode->next;
        }
    }
    i = 0;
    printf("\n\nlinked list after add");
    printf("\n");
    curr1 = head1->next;
    int iu = 0;
    while (curr1 != NULL)//Print linked list after add new data
    {
        iu++;
        if (iu == 2)
            printf("\n");
        i++;
        printf("[%d] %d %s %s %s %d %s %s", i, curr1->tag, curr1->name, curr1->date, curr1->fee_paid, curr1->age, curr1->university, curr1->job);
        curr1 = curr1->next;
    }
}
void Checksum(int struct_array_num, struct person* sort_tag)
{
    int total = 0;
    int sum = { 0 };
    FILE* check = fopen("checksum.txt", "w");

    int i, j, z;
    for (i = 0; i < struct_array_num; i++)//Compute the checksum of the original data
    {
        sum = 0;
        for (j = 0; j < strlen(sort_tag[i].name); j++)
        {
            sum += sort_tag[i].name[j];
        }

        total = sum;
        total = total & 0xFF;
        total = total ^ 255; //using bitwise ExclusiveOR
        total = total + 1;

        fprintf(check, "%d\n", total); //attach it to the copy.
        fprintf(check, "%s\n", sort_tag[i].name);
    }
    fclose(check);

    FILE* checkread = fopen("checksum.txt", "r");

    int check_count = 0;
    int checknumber = 0;

    char name2[20];
    int sum1[30] = { 0 };
    for (i = 0; i < struct_array_num; i++)
    {
        fscanf(checkread, "%d", &checknumber);
        fscanf(checkread, " %[^\n]", name2);
        for (j = 0; j < strlen(name2); j++)//Compute the checksum in the copied data 
        {
            sum1[i] += name2[j];
        }
        checknumber = checknumber + sum1[i];//add checknumber in copy file and checksum
        checknumber = checknumber & 0xff;
        if (checknumber == 0)//if checknumber is 0, data is same
        {
            check_count++; //if data is same, count plus 1
        }
    }
    if (check_count == struct_array_num)//if count equal size of struct, print "Two data is same" message
    {
        printf("\n\n[Copy Test] Two data is same");
    }
    else //else , print "Two data is not same" message
    {
        printf("\n\n[Copy Test] Two data is not same");
    }
    fclose(checkread);
}

int main()
{
    struct person p1[30];
    char File_Line[30][100];
    char File_Line1[30][100];
    int i, j, z;
    struct NODE* head = (struct NODE*)malloc(sizeof(struct NODE));
    head->next = NULL;
    struct NODE* address = (struct NODE*)malloc(sizeof(struct NODE));
    address = head;
    struct NODE* curr;

    //Setup(Read data, store in array and linked list)//
    setup(File_Line, p1, address);

    //Search for ¡°Choi"(struct array, linked list)//
    search_name(p1);
    curr = head->next;
    search_name2(curr);

    //Search for all from Gachon University (struct array, linked list)//
    search_uni(p1);
    curr = head->next;
    search_uni2(curr);

    //Sort the data in the array in tag# order//
    struct person sort_tag[31];
    Sort_array_tag(File_Line, sort_tag, File_Line1);

    //Create a linked list using the sorted data.//
    struct NODE* head1 = (struct NODE*)malloc(sizeof(struct NODE));
    head1->next = NULL;
    struct NODE* address1 = (struct NODE*)malloc(sizeof(struct NODE));
    address1 = head1;
    struct NODE* curr1 = head1->next;
    struct NODE* oldnode = (struct NODE*)malloc(sizeof(struct NODE));
    int id_num = 0;
    Create_sort_list(sort_tag, address1, head1, curr1);

    //Sort the data in the array in age group order//
    struct person sort_age[30];
    Sort_array_age(File_Line, sort_age, p1);

    //Write the sorted data to a text file.//
    Write_Sorted_File(sort_tag, sort_age, File_Line, File_Line1);

    //All¡°Choi¡±s canceled registration. Remove the data from(array, linked list)//
    remove_struct(sort_tag);
    oldnode = head1;
    curr1 = head1->next;
    remove_linkedlist(oldnode, curr1, &id_num, head1);

    //One¡°Paik¡±registered late. Add the data to(array, linked list)//
    int struct_array_num = Array_number;
    Add_Array(sort_tag, struct_array_num);
    Add_linked(sort_tag, oldnode, head1, curr1);

    //Copy the most recent data in the array for transmission to a remote computer//
    Checksum(struct_array_num, sort_tag);
}