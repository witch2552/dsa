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
struct Node* group(struct Node *head, int groupno)
{
    struct Node *current = head;
    struct Node *next = NULL;
    struct Node *prev = NULL;
    int count = 0;

   
    while (current != NULL && count < groupno)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = group(next, groupno);
    }

  
    return prev;
}


int main()
{
    int a, c;
    printf("Enter the head element: ");
    scanf("%d", &a);
    struct Node *head = CreateNode(a);

    while (1)
    {
        printf("Enter element 1 ,reverse group 2,display 3 : ");
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
            printf("Enter the number of groups to be divided : ");
            int groupno;
            scanf("%d", &groupno);
            head=group(head,groupno);
            break;

        case 3:
            display(head);
            break;
        default:
            return 0;
        }
    }
}