#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct phone_book
{
    char first_name[20];
    char last_name[20];
    char phone_no[10];
} phone_book;
phone_book persons[100];
int k = 0;
char temp[20];
int update_index = 1;
int choice = 1;
int match = 0;
void new_contact()
{
    printf("First Name:\n");
    scanf("%s", persons[k].first_name);
    printf("Last Name:\n");
    scanf("%s", persons[k].last_name);
    printf("Phone no:\n");
    scanf("%s", persons[k].phone_no);

    k++;
}
void print_detail()
{
    int count = 0;
    printf("-----------------------------------------------------------\n|First Name\t|\tLast Name\t|\tMonbile No|\n-----------------------------------------------------------\n");
    while (count < k)
    {
        for (int i = 0; i < 20; i++)
        {
            printf("%c", persons[count].first_name[i]);
        }
        printf("\t\t\t");
        for (int i = 0; i < 20; i++)
        {
            printf("%c", persons[count].last_name[i]);
        }
        printf("\t\t\t");
        for (int i = 0; i < 10; i++)
        {
            printf("%c", persons[count].phone_no[i]);
        }
        printf("\n");
        count++;
    }
}
void print_particular_person_detail(int index)
{
    printf("-----------------------------------------------------------\n|First Name\t|\tLast Name\t|\tMonbile No|\n-----------------------------------------------------------\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%c", persons[index].first_name[i]);
    }
    printf("\t\t");
    for (int i = 0; i < 20; i++)
    {
        printf("%c", persons[index].last_name[i]);
    }
    printf("\t\t");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", persons[index].phone_no[i]);
    }
    printf("\n");
}
void search()
{
    match=0;
    printf("Enter the person First Name/Last Name/Contact.");
    scanf("%s", temp);
    int length = strlen(temp);
    int first_name_occurence = 0;
    for (int i = 0; i < k; i++)
    {
        // serach by first name
        first_name_occurence = 0;
        int length1 = strlen(persons[i].first_name);
        for (int j = 0; j < length1; j++)
        {
            if (temp[first_name_occurence] == persons[i].first_name[j])
            {
                first_name_occurence++;
            }
            else if (first_name_occurence == length)
            {
                print_particular_person_detail(i);
                update_index = i;
                match++;
                break;
            }
            else
            {
                first_name_occurence = 0;
            }
        }
        // search by last name
        first_name_occurence = 0;
        int length2 = strlen(persons[i].last_name);
        for (int l = 0; l < length2; l++)
        {
            if (temp[first_name_occurence] == persons[i].last_name[l])
            {
                first_name_occurence++;
            }
            else
            {
                first_name_occurence = 0;
            }
            if (first_name_occurence == length)
            {
                print_particular_person_detail(i);
                update_index = i;
                match++;
                break;
            }
        }
        // search by phone no.
        first_name_occurence = 0;
        for (int m = 0; m < 10; m++)
        {
            if (temp[first_name_occurence] == persons[i].phone_no[m])
            {
                first_name_occurence++;
            }
            else
            {
                first_name_occurence = 0;
            }
            if (first_name_occurence == length)
            {
                print_particular_person_detail(i);
                update_index = i;
                match++;
                break;
            }
        }
    }
    if (match == 0)
    {
        printf("The person is not exist in the list.\n");
    }
}
void update()
{
    search();
    if(match!=0){
    printf("1.Update only first name.\n2.update only last name\n3.update only contact No\n4.Update All.\n5.Exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf(" New First Name:\n");
        scanf("%s", persons[update_index].first_name);
        break;
    case 2:
        printf(" New Last Nmae:\n");
        scanf("%s", persons[update_index].last_name);
        break;
    case 3:
        printf(" New Phone no:\n");
        scanf("%s", persons[update_index].phone_no);
        break;
    case 4:
        printf(" New First Name:\n");
        scanf("%s", persons[update_index].first_name);
        printf(" New Last Nmae:\n");
        scanf("%s", persons[update_index].last_name);
        printf(" New Phone no:\n");
        scanf("%s", persons[update_index].phone_no);
    case 5:
        break;
    default:
        printf("Invalid option choice!!!\n");
        break;
    }
        }
    choice = 1;
}

void delete()
{
    if (k == 0)
    {
        printf("The contact list is empty!!!\n");
        return;
    }
    search();
    if (match != 0)
    {
        for (int i = update_index; i < k; i++)
        {
            strcpy(persons[i].first_name, persons[i + 1].first_name);
            strcpy(persons[i].last_name, persons[i + 1].last_name);
            strcpy(persons[i].phone_no, persons[i + 1].phone_no);
        }
        k--;
    }
    if (match == 0)
    {
        printf("The person is not exist in the list.\n");
    }
}
int main()
{
    int mob;
    printf("---------Welcome to phoneBook----------\n");
    while (choice != 6)
    {
        printf("Enter 1 to add a new Contact.\nEnter 2 to show a Contact List.\nEnter 3 for search.\nEnter 4 for update.\nEnter 5 for delete\nEnter 6 for Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            new_contact();
            break;
        case 2:
            print_detail();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            delete ();
        case 6:
            break;
        default:
            printf("Wrong choice Enter.\n");
        }
    }
    return 0;
}