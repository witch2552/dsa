#include <stdio.h>

#include <stdlib.h>
#include <string.h>


struct Node {
    char name[100];
    struct Node *next;
};


struct Node* createNode(char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = newNode;  // Point to itself (circular linked list)
    return newNode;
}


struct Node* addSong(struct Node* head, char name[]) {
    struct Node* newNode = createNode(name);
    
   
    if (head == NULL) {
        head = newNode;
        return head;
    }

    
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;  
    return head;
}


struct Node* removeSong(struct Node* head, char name[]) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

   
    do {
        if (strcmp(current->name, name) == 0) {
            
            if (current->next == head && prev == NULL) {
                free(current);
                return NULL;
            }

            
            if (current == head) {
                
                struct Node* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = head->next;
                head = head->next;
                free(current);
                return head;
            }

            
            prev->next = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Song not found in the playlist.\n");
    return head;
}


void displayPlaylist(struct Node* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    struct Node* temp = head;
    int index = 1;
    do {
        printf("%d. %s\n", index++, temp->name);
        temp = temp->next;
    } while (temp != head);
}


void playSongs(struct Node* head) {
    if (head == NULL) {
        printf("Playlist is empty. No songs to play.\n");
        return;
    }

    struct Node* temp = head;
    char command;

    do {
        printf("Now playing: %s\n", temp->name);
        printf("Press 'n' for next song or 'q' to quit: ");
        scanf(" %c", &command);

        if (command == 'n') {
            temp = temp->next; 
        }

    } while (command != 'q');
}


int main() {
    struct Node* head = NULL;
    int c;
    char songName[100];

    while (1) {
       
        printf("1:Add song | 2: remove song | 3:Display | 4: Loop | 5:exit ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", songName); 
                head = addSong(head, songName);
                break;
            case 2:
                printf("Enter the name of the song to remove: ");
                scanf("%s", songName); 
                head = removeSong(head, songName);
                break;
            case 3:
                printf("\nPlaylist:\n");
                displayPlaylist(head);
                break;
            case 4:
                playSongs(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}