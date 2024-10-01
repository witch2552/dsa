#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node * next;
};

//first insertion
struct node *createnode(int data){
struct node *newnode = (struct node*) malloc(sizeof(struct node));
newnode -> data = data;
newnode -> next = NULL;
return newnode;
}

//print
void printfn(struct node *head){
    struct node *cur = head;
    while(cur!=NULL){
        printf("%d",cur -> data);
        cur = cur -> next;
    }
}


int main(){
        int option,a;
        printf("enter the element ");
        scanf("%d",&a);
        struct node *head = creatnode(a);
        
    while (1)
    {   printf("enter option 1 : 1st ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
          66666666666666666666669999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999996  
                                                                                                                                                                 
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}