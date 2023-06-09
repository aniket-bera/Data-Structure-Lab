#include<stdio.h>

int stack[100];
int top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char exp[50], a;
    int n1, n2, n3, num, i;
    printf("\nEnter the Postfix Expression: ");
    scanf("%s", exp);
    printf("\nEvaluating Postfix Expression: ");
    i = 0;
    while (exp[i] != '\0'){
        a = exp[i];
        
        if(a >= '0' && a <= '9'){
            num = a-48;
            push(num);
        }

        else{
            n1 = pop();
            n2 = pop();
            switch(a){
                case '+':
                    n3 = n1 + n2;
                    break;
                
                case '-':
                    n3 = n2 - n1;
                    break;
                
                case '*':
                    n3 = n1 * n2;
                    break;
                
                case '/':
                    n3 = n2 / n1;
                    break;
            }
            push(n3);
        }
        i++;
    }
    
    printf("%d ", pop());
    
    return 0;
}