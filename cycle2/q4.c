#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
void swap(struct Node *head, int d1, int d2)
{
    if (d1 == d2)
    {
        return;
    }

    struct Node *prev1 = NULL, *prev2 = NULL;
    struct Node *first = head, *second = head;

    
    while (first && first->data != d1)
    {
        prev1 = first;
        first = first->next;
    }


    while (second && second->data != d2)
    {
        prev2 = second;
        second = second->next;
    }

  
    if (!first || !second)
    {
        printf("One or both elements not found in the list.\n");
        return;
    }

   
    if (prev1)
        prev1->next = second;
    else
        head = second;

    if (prev2)
        prev2->next = first;
    else
        head = first;

  
    struct Node *temp = first->next;
    first->next = second->next;
    second->next = temp;
}

int main()
{
    int a, c;
    printf("Enter the head element: ");
    scanf("%d", &a);
    struct Node *head = CreateNode(a);

    while (1)
    {
        printf("Enter element 1 ,swap element 2,display 3 : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &a);
            struct Node *newNode = CreateNode(a);
            struct Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = newNode;
            break;
        case 2:
            printf("Enter the data that should be swapped ");
            int d1, d2;
            scanf("%d %d", &d1, &d2);
            swap(head, d1, d2);
            break;

        case 3:
            display(head);
            break;
        default:
            return 0;
        }
    }
}