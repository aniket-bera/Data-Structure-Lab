#include<stdio.h>
#include<stdlib.h> 

typedef struct node{
	int data;
	struct node *left, *right;
	int ht;
}node;

node *insert(node *, int);
int height(node *);
int balance(node *);
node *rotateright(node *);
node *rotateleft(node *);
node *rightR(node *);
node *leftL(node *);
node *leftR(node *);
node *rightL(node *);
void inorder(node *);
 
int main(){
	int k, n, i, choice;
	node *root = NULL;
	
	while(1){
		printf("\n1 --> Create");
		printf("\n2 --> Traverse");
		printf("\n3 --> Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: printf("\nEnter no. of elements: ");
					scanf("%d", &n);
					printf("\nEnter tree data: ");
					
					root = NULL;
					
					for(i = 0; i < n; i++){
						scanf("%d", &k);
						root = insert(root, k);
					}
			break;
			
			case 2: printf("\nInorder sequence: ");
					inorder(root);
			break;
			
			case 3: exit(0);
			
			default:printf("\n\nWorng choice!! Please enter valid choice?\n");
		}
	}
	
	return 0;
}

node * insert(node *tree, int k){
	if(tree == NULL){
		tree = (node*)malloc(sizeof(node));
		tree->data = k;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if(k > tree->data){ 
		tree->right = insert(tree->right, k);
		if(balance(tree) == -2)
		if(k > tree->right->data)
			tree = rightR(tree);
		else{
			tree = rightL(tree);
		}
	}
	else if(k < tree->data){
		tree->left = insert(tree->left, k);
		if(balance(tree) == 2)
		if(k < tree->left->data)
			tree = leftL(tree);
		else{
			tree = leftR(tree);
		}
	}
	
	return tree;
}
 
int height(node *tree){
	if(tree == NULL){
		return 0;
	}
	return tree->ht;
}

int balance(node *tree){
	if(tree == NULL){
		return 0;	
	} 
	return height(tree->left) - height(tree->right);
}
 
node * rotateright(node *k){
	node *y;
	
	y = k->left;
	k->left = y->right;
	y->right = k;
	k->ht = height(k);
	y->ht = height(y);
	
	return y;
}
 
node * rotateleft(node *k){
	node *y;
	
	y = k->right;
	k->right = y->left;
	y->left = k;
	k->ht = height(k);
	y->ht = height(y);
	
	return y;
}
 
node * rightR(node *tree){
	tree = rotateleft(tree);
	return tree;
}
 
node * leftL(node *tree){
	tree = rotateright(tree);
	return tree;
}
 
node * leftR(node *tree){
	tree->left = rotateleft(tree->left);
	tree = rotateright(tree);
	return tree;
}
 
node * rightL(node *tree){
	tree->right = rotateright(tree->right);
	tree = rotateleft(tree);
	return tree;
}

void inorder(node *tree){
	if(tree != NULL){
		inorder(tree->left);
		printf("%d ", tree->data);
		inorder(tree->right);
	}
}