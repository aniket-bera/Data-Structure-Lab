#include <stdio.h>
#include<stdlib.h>

#define MAX 100
 
void ENQUE(char);
void DELQUE();
void DISPLAY();
char queue[MAX];

int rear = - 1, front = - 1;

int main(){
    int choice;
    char item;
    while(1){
        printf("\n1 --> Insert element to queue");
        printf("\n2 --> Delete element from queue");
        printf("\n3 --> Display all elements of queue");
        printf("\n4 --> Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1: printf("\nInsert the element in queue: ");
                    scanf(" %c", &item);
                    ENQUE(item);
                    break;
            
            case 2: DELQUE();
                    break;
            
            case 3: DISPLAY();
                    break;
            
            case 4: exit(0);
            
            default:printf("\n\nWorng choice!! Please enter valid choice(1-4)? ");
        }
    }
}
 
void ENQUE(char item){
    if (rear == MAX - 1)
        printf("\nQueue Overflow");
    else{
        if (front == - 1)
            front = 0;
            rear = rear + 1;
            queue[rear] = item;
    }
}
 
void DELQUE(){
    if (front == - 1 || front > rear){
        printf("\nQueue Underflow");
        return;
    }
    else{
        printf("\nDeleted element: %c\n", queue[front]);
        front = front + 1;
    }
}
 
void DISPLAY(){
    int i;
    if (front == - 1)
        printf("\nQueue is empty");
    else{
        printf("\nQueue elements are: ");
        for (i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        
        printf("\n");
    }
}