#include <stdio.h>
#include<stdlib.h>
#define MAX 5

char cq[MAX];
int front = -1, rear = -1;

void CENQUE(char);
void CDELQUE();
void CDISPLAY();

int main(){
    int choice;
    char item;
    
    while(1){
        printf("\nInsert    ---> 1");
        printf("\nDelete    ---> 2");
        printf("\nDisplay   ---> 3");
        printf("\nExit      ---> 4");
        
        printf("\nEnter Your Choice(1 to 4): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: printf("\n\nEnter the data to be inserted: ");
                    scanf(" %c", &item);
                    CENQUE(item);
                    break;
            
            case 2: CDELQUE();
                    break;
            
            case 3: CDISPLAY();
                    break;
            
            case 4: exit(0);
            
            default:printf("\n\nWorng choice!! Please enter valid choice(1-4)? ");
        }
    }
}

void CENQUE(char item){ //insert element
    if(front == (rear+1)%MAX){
        printf("\n\nCircular Queue Overflow");
    }
    else{
        if(front == -1)
            front = rear = 0;
        else
            rear = (rear+1)%MAX;
            cq[rear] = item;
    }
}

void CDELQUE(){ //delete element
    char item;
    if(front == -1){
        printf("\n\nCircular Queue Underflow");
    }
    else{
        item = cq[front];
        printf("\n\nDeleted entered data from the queue is: %c", item);
                               
        if(front == rear){ //only one element at a time
            front = rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
    }
}

void CDISPLAY(){    //display element
    int i;
    if(front == -1){
        printf("\n\nCircular Queue Empty");
    }
    else{
        printf("\n\nCircular Queue contents are: ");
        for(i = front; i != rear ; i = (i+1)%MAX){
            printf(" %c", cq[i]);
        }
        printf(" %c", cq[i]);
    }
}