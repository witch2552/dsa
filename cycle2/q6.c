#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *current = head;
    do
    {
        printf(" %d", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

struct Node *insertend(struct Node *end, int a)
{
    struct Node *new = createNode(a);
    if (end == NULL)
    {
        new->next = new;
        return new;
    }
    new->next = end->next;
    end->next = new;
    return new;
}
struct Node *insertHead(struct Node *head, int a)
{
    struct Node *new = createNode(a);
    struct Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    new->next = head;
    current->next = new;
    return new;
}

void insertany(struct Node *head, int b, int a)
{
    struct Node *current = head;
    struct Node *new = createNode(a);
    do
    {
        if (current->data == b)
        {
            new->next = current->next;
            current->next = new;
            break;
        }
        current = current->next;
    } while (current != head);
}
struct Node *delete(struct Node *head, int a)
{
    if (head == NULL)
    {
        printf("List is empty, cannot delete\n");
        return NULL;
    }

    struct Node *current = head;
    struct Node *last = head;


    if (current->data == a)
    {
       
        if (current->next == head)
        {
            free(current);
            return NULL; 
        }
        else
        {
            
            while (last->next != head)
            {
                last = last->next;
            }
            last->next = current->next; 
            head = current->next;       
            free(current);             
            return head;                
        }
    }

 
    do
    {
        last = current;
        current = current->next;

        if (current->data == a)
        {
            last->next = current->next; 
            free(current);              
            return head;
        }

    } while (current != head);

    
    printf("Element not found, try again\n");
    return head;}

int main()
{
    printf("Enter head element: ");
    int a, b;
    scanf("%d", &a);
    struct Node *head = createNode(a);
    head->next = head;
    struct Node *end = head;

    while (1)
    {
        printf("Insert at end 1; At head 2; other position 3; delete at any position 4 ; display 5 ; exit 6 ");
        int c;
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &a);
            end = insertend(end, a);
            break;
        case 3:
            printf("Enter the value to be inserted: ");
            scanf("%d", &a);
            printf("Current linked list is: ");
            display(head);
            printf("Enter the element to the left of the element to be inserted: ");
            scanf("%d", &b);
            insertany(head, b, a);
            break;
        case 2:
            printf("Enter the value to be inserted ");
            scanf("%d", &a);
            head = insertHead(head, a);
            break;
        case 4:
            printf("Enter the element to be deleted :");
            scanf("%d",&a);
            head=delete(head,a);
            break;

        case 5:
            display(head);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}