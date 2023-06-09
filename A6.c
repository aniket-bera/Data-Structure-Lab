#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;

void create(int info){
    struct node *q,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = info;
    temp->link = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        q = start;
        while(q->link != NULL)
        q = q->link;
        q->link = temp;
    }
}

void insert_at_beg(){
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;

    temp->link = start;
    start = temp;
}

void insert_at_end(){
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
  
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
  
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void insert_at_pos(){
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    printf("\nEnter position: ");
    scanf("%d", &pos);

    printf("\nEnter your data: ");
    scanf("%d", &data);
  
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void del_from_beg(){
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void del_from_end(){
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void del_from_pos(){
    struct node *temp, *position;
    int i = 1, pos;
  
    if (start == NULL)
        printf("\nList is empty\n");
  
    else {
        printf("\nEnter position: ");
  
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;

        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
  
        position = temp->link;
        temp->link = position->link;

        free(position);
    }
}

void traverse(){
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
  
    else {
        temp = start;
        printf("\nLinklist elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main(){
    int n, m, i, choice;
    char menu;

    printf("\nNo. of nodes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\nEnter the node: ", &n);
        scanf("%d", &m);
        create(m);
    }

    while(1) {
        printf("\na --> Insertion");
        printf("\nb --> Delation");
        printf("\nc --> Traverse the nodes");
        printf("\nd --> Exit");

        printf("\n\nEnter Choice: ");
        scanf(" %c", &menu);
        
        switch (menu){
            case 'a':
            case 'A':
                    printf("\n1 --> Insert at begining");
                    printf("\n2 --> Insert at end");
                    printf("\n3 --> Insert at any position");

                    printf("\n\nEnter Choice: ");
                    scanf("%d", &choice);
                    
                    switch (choice){
                        case 1: insert_at_beg();
                                break;
                        
                        case 2: insert_at_end();
                                break;
                        
                        case 3: insert_at_pos();
                                break;

                        default:printf("\n\nWorng choice!!");
                    }
                    break;

            case 'b':
            case 'B':
                    printf("\n1 --> Delete at begining");
                    printf("\n2 --> Delete at end");
                    printf("\n3 --> Delete at any position");

                    printf("\n\nEnter Choice: ");
                    scanf("%d", &choice);
                    
                    switch (choice){
                        case 1: del_from_beg();
                                break;
                        
                        case 2: del_from_end();
                                break;
                        
                        case 3: del_from_pos();
                                break;
                        
                        default:printf("\n\nWorng choice!!");
                    }
                    break;
            
            case 'c':
            case 'C':
                    traverse();
                    break;
            
            case 'd':
            case 'D':
                    exit(0);

            default: printf("\n\nWorng choice!! Please enter valid choice?\n");
        }
    }
    
    return 0;
}