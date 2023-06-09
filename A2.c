#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int s[MAX], choice, n, top, x, i;

void push();
void pop();
void display();

int main(){
    top = -1;     // Initially there is no element in stack
    printf("\nEnter the size of STACK: ");
    scanf("%d", &n);
    do{
        printf("\n1 --> PUSH");
        printf("\n2 --> POP");
        printf("\n3 --> DISPLAY");
        printf("\n4 --> EXIT");
        
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);

            default:printf("\nInvalid Choice\n");
                    printf("_______________________________\n");
        }
    }
    while(choice!=4);
    return 0;
}

void push(){
    if(top >= n - 1){
        printf("\nSTACK OVERFLOW");    
    }
    else{
        printf("Enter a value to be pushed: ");
        scanf("%d",&x);
        printf("_______________________________\n");
        top++;         // TOP is incremented after an element is pushed
        s[top] = x;   // The pushed element is made as TOP
    }
}

void pop(){
    if(top <= -1){
        printf("\nSTACK UNDERFLOW");
        printf("_______________________________\n");
    }
    else{
        printf("\nThe popped element is %d\n", s[top]);
        printf("_________________________________\n");   
        top--;     //  Decrement TOP after a pop
    }
}

void display(){
    if(top >= 0){
        printf("\nELEMENTS IN THE STACK --> ");
        for(i = top ; i >= 0 ; i--)
            printf("%d\t", s[i]);
        printf("\n______________________\n");
    }
    else{
        printf("\nEMPTY STACK");
        printf("_______________________________\n");
    }
}