#include<stdio.h>   
#include<stdlib.h>  

struct node{  
    int data;   
    struct node *next;  
};  
struct node *front;  
struct node *rear;   

void insert();  
void delete();  
void display();  

int main(){  
    int choice;   
    
    while(1){
        printf("\n1 --> Insert element to queue");
        printf("\n2 --> Delete element from queue");
        printf("\n3 --> Display all elements of queue");
        printf("\n4 --> Exit");

        printf("\n\nEnter your choice: ");  
        scanf("%d",& choice);  
        
        switch(choice){  
            case 1: insert();  
                    break;  
            
            case 2: delete();  
                    break;
            
            case 3: display();  
                    break;  
            
            case 4: exit(0);  
                    break;  
            
            default:printf("\nWorng choice!! Please enter valid choice?"); 
        }  
    }  
}

void insert(){  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL){  
        printf("\nOverflow");  
        return;  
    }  
    else{   
        printf("\nEnter value: ");  
        scanf("%d", &item);  
        ptr -> data = item;  
        if(front == NULL){  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else{  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}

void delete(){  
    struct node *ptr;  
    if(front == NULL){  
        printf("\nUnderlow");  
        return;  
    }  
    else{  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}

void display(){  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL){  
        printf("\nEmpty queue");  
    }  
    else{
        printf("\nQueue elements are:");  
        while(ptr != NULL){  
            printf(" %d", ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}