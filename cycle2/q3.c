#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

struct Node *CreateNode(int data, int pow)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = data;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertion(struct Node *head)
{
    struct Node *newNode;
    struct Node *curr = head;
    int cont = 1, a, b, d = 1, c;

    while (1)
    {
        d++;
        printf("Enter the coeff and power of %d element ", d);
        scanf("%d %d", &a, &b);
        newNode = CreateNode(a, b);
        curr->next = newNode;
        printf("Want to continue?1/0 ");
        scanf("%d", &c);
        curr = curr->next;
        if (c == 0)
        {
            break;
        }
    }
}

struct Node *Sum(struct Node *h1, struct Node *h2)
{
    struct Node *resulth = NULL;
    struct Node **lastPtr = &resulth;

    while (h1 != NULL && h2 != NULL)
    {
        struct Node *newNode;
        if (h1->pow > h2->pow)
        {
            newNode = CreateNode(h1->coeff, h1->pow);
            h1 = h1->next;
        }
        else if (h1->pow < h2->pow)
        {
            newNode = CreateNode(h2->coeff, h2->pow);
            h2 = h2->next;
        }
        else
        {
            newNode = CreateNode(h1->coeff + h2->coeff, h1->pow);
            h1 = h1->next;
            h2 = h2->next;
        }
        *lastPtr = newNode;
        lastPtr = &(newNode->next);
    }

    while (h1 != NULL)
    {
        *lastPtr = CreateNode(h1->coeff, h1->pow);
        lastPtr = &((*lastPtr)->next);
        h1 = h1->next;
    }

    while (h2 != NULL)
    {
        *lastPtr = CreateNode(h2->coeff, h2->pow);
        lastPtr = &((*lastPtr)->next);
        h2 = h2->next;
    }

    return resulth;
}

struct Node *Multiply(struct Node *h1, struct Node *h2)
{
    struct Node *result = NULL;
    struct Node *tempH2 = h2;

    while (h1 != NULL)
    {
        while (h2 != NULL)
        {
            int coeff = h1->coeff * h2->coeff;
            int pow = h1->pow + h2->pow;

            struct Node *newNode = CreateNode(coeff, pow);
            result = Sum(result, newNode);

            h2 = h2->next;
        }
        h2 = tempH2;
        h1 = h1->next;
    }

    return result;
}

void display(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf(" %d*x^%d", curr->coeff, curr->pow);
        if (curr->next != NULL)
            printf(" +");
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int c, a, b;
    printf("Enter 1 for addition 2 for multiplication: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("Enter the coeff and power of first element of first polynomial: ");
        scanf("%d %d", &a, &b);
        struct Node *head1 = CreateNode(a, b);
        insertion(head1);
        display(head1);

        printf("Enter the coeff and power of first element of second polynomial: ");
        scanf("%d %d", &a, &b);
        struct Node *head2 = CreateNode(a, b);
        insertion(head2);
        display(head2);

        struct Node *sum = Sum(head1, head2);
        printf("After summation the obtained polynomial is: ");
        display(sum);
        break;

    case 2:
        printf("Enter the coeff and power of first element of first polynomial: ");
        scanf("%d %d", &a, &b);
        struct Node *head3 = CreateNode(a, b);
        insertion(head3);
        display(head3);

        printf("Enter the coeff and power of first element of second polynomial: ");
        scanf("%d %d", &a, &b);
        struct Node *head4 = CreateNode(a, b);
        insertion(head4);
        display(head4);

        struct Node *product = Multiply(head3, head4);
        printf("After multiplication the obtained polynomial is: ");
        display(product);
        break;

    default:
        printf("Invalid choice\n");
        return 0;
    }

    return 0;
}