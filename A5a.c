#include<stdio.h>

char stack[100];
int top;

void push(char x){
    stack[++top] = x;
}

char pop(){
    return stack[top--];
}

int precendence(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main(){
    char exp[100], a, x;
    int i;
    top=-1;
    printf("\nEnter the Infix Expression: ");
    scanf("%s", exp);
    printf("\nEquivalent Postfix Expression: ");
    i = 0;
    while (exp[i] != '\0'){
        a = exp[i];
        
        if(((a) >= '0' && (a) <= '9')||
            ((a) >= 'a' && (a) <= 'z')||
            ((a) >= 'A' && (a) <= 'Z'))
            printf("%c ", a);
        
        else if(a == '(')
            push(a);
        
        else if(a == ')'){
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        
        else{
            while(precendence(stack[top]) >= precendence(a))
                printf("%c ", pop());
            push(a);
        }
        
        i++;
    }
    
    while(top != -1)
        printf("%c ", pop());
    
    return 0;
}