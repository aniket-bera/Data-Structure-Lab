#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}bst;

void insert(bst *, bst *);
void preorder(bst *);
void inorder(bst *);
void postorder(bst *);

int main(){
    int choice, ch;
    bst *root, *temp;
    root = NULL;
    
    printf("\n1 --> Create");
    printf("\n2 --> Traverse");
    printf("\n3 --> Exit");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: temp = (bst*)malloc(sizeof(bst));
                    temp->left = NULL;
                    temp->right = NULL;
                    
                    printf("Enter your data: ");
                    scanf("%d", &temp->data);

                    if(root == NULL){
                        root = temp;
                    }
                    else{
                        insert(root, temp);
                    }
                    break;
                    
            case 2: if(root == NULL){
                        printf("\nTree is empty!!!");
                    }
                    else{
                        printf("\n1 --> Preorder");
                        printf("\n2 --> Inorder");
                        printf("\n3 --> Postorder");
                        printf("\n4 --> Exit");

                        printf("\nEnter your choice: ");
                        scanf("%d", &ch);

                        switch(ch){
                            case 1: printf("\nPreorder: ");
                                    preorder(root);
                                    break;
                                
                            case 2: printf("\nInorder: ");
                                    inorder(root);
                                    break;
                                
                            case 3: printf("\nPostorder: ");
                                    postorder(root);
                                    break;
                                
                            case 4: exit(0);
                                
                            default: printf("\nWorng choice!! Please enter valid choice?\n");
                        }
                    }
                    break;
                
            case 3: exit(0);

            default: printf("\n\nWorng choice!! Please enter valid choice?\n");
        }
    }

    return 0;
}

void insert(bst *root, bst *new){
    if(new->data < root->data){
        if(root->left == NULL){
            root->left = new;
        }
        else{
            insert(root->left, new);
        }
    }
    if(new->data > root->data){
        if(root->right == NULL){
            root->right = new;
        }
        else{
            insert(root->right, new);
        }
    }
}

void preorder(bst *temp){
    if(temp != NULL){
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(bst *temp){
    if(temp != NULL){
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(bst *temp){
    if(temp != NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}