#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int data){
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    return new;
}
struct Node* addElement(struct Node* head,int data){
    struct Node* current=head;
    struct Node* new=createNode(data);
    if(head==NULL){
        return new;
    }
    while(current->next!=NULL){
        current=current->next;
    }
    new->prev=current;
    current->next=new;
    return head;
}
void display(struct Node* head){
    struct Node* current=head;
    if(current==NULL){
        printf("List is empty ");
        return;
    }
    while(current!=NULL){
        printf(" %d",current->data);
        current=current->next;
    }
    printf("\n");
}
struct Node* deleteElement(struct Node* head, int data) {
    struct Node* current = head;
    
    
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }
    
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    
    if (current == NULL) {
        printf("Node with data %d not found\n", data);
        return head;
    }

    
    if (current == head) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
        return head;
    }

    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    return head;
}

int main(){
    printf("Enter the data of the head element ");
    int a,c;
    scanf("%d",&a);
    struct Node* head=createNode(a);
    while(1){
        printf("1:Add end |2: delete |3: Display ");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter the data to be added : ");
                scanf("%d",&a);
                head=addElement(head,a);
                break;
            case 2:
                printf("Enter the element to be deleted : ");
                scanf("%d",&a);
                head=deleteElement(head,a);
                break;
            case 3:
                printf("Doubly linked list is :");
                display(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice ");
                break;

        }
    }
}