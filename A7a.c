#include<stdio.h>  
#include<stdlib.h>  
 
struct node{  
    int val;  
    struct node *next;  
};  
struct node *head;  

void push();  
void pop();  
void display(); 

int main(){  
    int choice;     

    while(1){ 
        printf("\n1 --> PUSH");
        printf("\n2 --> POP");
        printf("\n3 --> DISPLAY");
        printf("\n4 --> EXIT");

        printf("\n\nEnter your choice: ");        
        scanf("%d", &choice);  
        switch(choice){  
            case 1: push();  
                    break;  

            case 2: pop();  
                    break;  

            case 3: display();  
                    break;  

            case 4: exit(0);   

            default:printf("\nWorng choice!! Please enter valid choice?");
        } 
    }
    return 0; 
}

void push(){  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL){  
        printf("\nUable to push the element");   
    }  
    else{  
        printf("\nEnter the value: ");  
        scanf("%d", &val);  
        if(head==NULL){         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else{  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("\nItem pushed");  
    }  
}  

void pop(){  
    int item;  
    struct node *ptr;  
    if (head == NULL)  {  
        printf("\nUnderflow");  
    }  
    else{  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("\nItem popped");
    }  
}

void display(){  
    int i;  
    struct node *ptr;  
    ptr = head;  
    if(ptr == NULL){  
        printf("\nStack is empty");  
    }  
    else{  
        printf("\nStack elements are:");  
        while(ptr != NULL){  
            printf(" %d", ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}