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

void enqueue(struct Node *head, int data)
{
    struct Node *new = createNode(data);
    struct Node *current = head;
    while (1)
    {
        if (current->next == NULL)
        {
            current->next = new;
            break;
        }
        current = current->next;
    }
}

struct Node *dequeue(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue is empty, cannot dequeue\n");
        return NULL;
    }
    else
    {
        struct Node *sec = head->next;
        free(head);
        return sec;
    }
}

void displayQueue(struct Node *head)
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void push(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *cur = *head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void pop(struct Node **head)
{
    if ((*head)->next == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        struct Node *cur = *head;
        struct Node *cur2 = cur->next;
        while (1)
        {
            if (cur2->next == NULL)
            {
                cur->next = NULL;
                free(cur2);
                break;
            }
            cur = cur->next;
            cur2 = cur->next;
        }
    }
}

void displayStack(struct Node *head)
{
    struct Node *cur = head;
    while (cur != NULL)
    {
        printf(" %d", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void enqueueCircular(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

struct Node *dequeueCircular(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty, cannot dequeue\n");
        return NULL;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return NULL;
    }
    struct Node *last = *head;
    while (last->next != *head)
    {
        last = last->next;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    last->next = *head;
    free(temp);
    return *head;
}

void displayCircularQueue(struct Node *head)
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
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

int main()
{
    int choice, subchoice, data;
    struct Node *stackHead = NULL, *queueHead = NULL, *circularQueueHead = NULL;

    while (1)
    {

        printf(" 1:Stack | 2:Queue | 3:Circular Queue | 4:Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("1:Push | 2:Pop | 3:display | 4:Exit ");
                scanf("%d", &subchoice);
                if (subchoice == 1)
                {
                    printf("Enter value to push: ");
                    scanf("%d", &data);
                    if (stackHead == NULL)
                    {
                        stackHead = createNode(data);
                    }
                    else
                    {
                        push(&stackHead, data);
                    }
                }
                else if (subchoice == 2)
                {
                    pop(&stackHead);
                }
                else if (subchoice == 3)
                {
                    displayStack(stackHead);
                }
                else
                {
                    break;
                }
            }
            break;

        case 2:
            while (1)
            {
                printf("1:Enqueue | 2:Dequeue | 3:Display | 4:Exit ");
                scanf("%d", &subchoice);
                if (subchoice == 1)
                {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &data);
                    if (queueHead == NULL)
                    {
                        queueHead = createNode(data);
                    }
                    else
                    {
                        enqueue(queueHead, data);
                    }
                }
                else if (subchoice == 2)
                {
                    queueHead = dequeue(queueHead);
                }
                else if (subchoice == 3)
                {
                    displayQueue(queueHead);
                }
                else
                {
                    break;
                }
            }
            break;

        case 3:
            while (1)
            {
                printf("1:Enqueue | 2:Dequeue | 3:Display | 4:Exit ");
                scanf("%d", &subchoice);
                if (subchoice == 1)
                {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &data);
                    enqueueCircular(&circularQueueHead, data);
                }
                else if (subchoice == 2)
                {
                    circularQueueHead = dequeueCircular(&circularQueueHead);
                }
                else if (subchoice == 3)
                {
                    displayCircularQueue(circularQueueHead);
                }
                else
                {
                    break;
                }
            }
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}