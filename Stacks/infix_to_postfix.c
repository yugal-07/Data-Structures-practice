#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x){
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main(){

    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0'){

        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }

        else if(infix[i] == '('){
            push(infix[i]);
        }

        else if(infix[i] == ')'){
            while(stack[top] != '('){
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        else{
            while(priority(stack[top]) >= priority(infix[i])){
                postfix[j++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
