#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int roll;
    char name[30];
    int mark;
    struct Node *next;
};

struct Node *CreateNode(int roll, int mark, char name[30])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->mark = mark;
    newNode->next = NULL;
    return newNode;
}

void insertStudent(struct Node *head, char name[], int rollNo, int totalMarks)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    struct Node *new = CreateNode(rollNo, totalMarks, name);
    head->next = new;
    new->next = NULL;
}
void search(struct Node *head, int a)
{
    while (head != NULL)
    {
        if (head->roll == a)
        {
            printf("Name of the student is : %s \n", head->name);
            printf("Roll number of the student is : %d \n", a);
            printf("Total marks of the student is : %d\n", head->mark);
            return;
        }
        else
        {
            head = head->next;
        }
    }
    printf("Student record not found ");
}
struct Node *deleteStudent(struct Node *head, int roll)
{
    struct Node *last = head;
    struct Node *current = head;
    if (head == NULL)
    {
        printf("List is empty");
        return head;
    }
    if (current->roll == roll)
    {
        head = current->next;
        free(current);
        return head;
    }

    while (current!=NULL && current->roll != roll)
    {
        last = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Student not found");
        return head;
    }

    
        last->next = current->next;
        free(current);
        return head;
    
    
}
void displayall(struct Node *head)
{
    int a = 1;
    while (head != NULL)
    {
        printf("Name of the student %d is: %s \n", a, head->name);
        printf("Roll number of the student is : %d \n", head->roll);
        printf("Total marks of the student is : %d\n", head->mark);
        head = head->next;
    }
}
int main()
{
    struct Node *head;
    int c, roll, mark;
    char name[100];
    printf("Enter first student name: ");
    scanf(" %s", name);
    printf("Enter first roll number: ");
    scanf("%d", &roll);
    printf("Enter first total marks: ");
    scanf("%d", &mark);
    head = CreateNode(roll, mark, name);

    while (1)
    {
        printf("1:Create a node | 2:Search | 3:Delete | 4:Display ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter student name: ");
            scanf(" %s", name);
            printf("Enter roll number: ");
            scanf("%d", &roll);
            printf("Enter total marks: ");
            scanf("%d", &mark);
            insertStudent(head, name, roll, mark);
            break;

        case 2:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            search(head, roll);
            break;

        case 3:
            printf("Enter roll number of the student to delete: ");
            scanf("%d", &roll);
            head = deleteStudent(head, roll);
            break;

        case 4:

            displayall(head);
            break;

        case 5:

            return 0;

        default:
            printf("Invalid choice. Please try again ");
        }
    }
    return 0;
}