#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    int coeff;
    int pow;
    struct link * next;
}poly;

void createpoly(poly **);
void dispoly(poly *);
void addpoly(poly **, poly *, poly *);

int main(){
    int ch;
    
    do{
        poly *poly1, *poly2, *poly3;
 
        printf("\nCreate 1st expression\n");
        createpoly(&poly1);
        dispoly(poly1);
 
        printf("\n\nCreate 2nd expression\n");
        createpoly(&poly2);
        dispoly(poly2);
 
        addpoly(&poly3, poly1, poly2);
        dispoly(poly3);
 
        printf("\n\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    }while(ch);
    
    return 0;
}

void createpoly(poly **node) {
    int coeff, pow, ch;
    poly *temp;
    temp = (poly *)malloc(sizeof(poly));
    *node = temp;
    
    do{
        printf("\nEnter Coeff: ");
        scanf("%d", &coeff);
        temp->coeff = coeff;
        
        printf("\nEnter Pow: ");
        scanf("%d", &pow);
        temp->pow = pow;
 
        temp->next = NULL;
 
        printf("\nContinue adding more terms to the polynomial list?(Y = 1/N = 0): ");
        scanf("%d", &ch);

        if(ch){
            temp->next = (poly *)malloc(sizeof(poly));
            temp = temp->next;
            temp->next = NULL;
        }
    }while(ch);
}
 
void dispoly(poly *node) {
    printf("\nThe polynomial expression is: ");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}

void addpoly(poly **result, poly *poly1, poly *poly2){
    poly *temp;
    temp = (poly *)malloc(sizeof(poly));
    temp->next = NULL;
    *result = temp;
 
    while(poly1 && poly2){
        if(poly1->pow > poly2->pow){
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow){
            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else{
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if(poly1 && poly2){
            temp->next = (poly *)malloc(sizeof(poly));
            temp = temp->next;
            temp->next = NULL;
        }
    }
 
    while(poly1 || poly2){
        temp->next = (poly *)malloc(sizeof(poly));
        temp = temp->next;
        temp->next = NULL;
 
        if(poly1){
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        
        if(poly2){
            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
 
    printf("\n\nAddition of polynomial expressions:-\n");
}