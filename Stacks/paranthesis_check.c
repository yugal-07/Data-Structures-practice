//stack ADT and paranthesis matching
#include <stdio.h>
#include <string.h>
#define max 101

int arr[max];
int top = -1;

void push(int value) {
    arr[++top] = value;
}

void pop() {
    top--;
}

int isempty() {
    return top == -1;
}

void paranthesis_matching(char st[]) {
    top = -1;  // reset stack for each call
    int len = strlen(st);

    for (int i = 0; i < len; i++) {
        if (st[i] == '[' || st[i] == '(' || st[i] == '{') {
            push(st[i]);
        }
        else if (!isempty() &&
                 ((st[i] == '}' && arr[top] == '{') ||
                  (st[i] == ')' && arr[top] == '(') ||
                  (st[i] == ']' && arr[top] == '['))) {
            pop();
        }
        else if (st[i] == ']' || st[i] == ')' || st[i] == '}') {
            push(st[i]);  // mismatched closer, push to mark imbalance
        }
    }

    if (isempty()) {
        printf("parenthesis balanced\n");
    } else {
        printf("parenthesis unbalanced\n");
    }
}

int main() {
    char st[100];
    printf("Enter the equation: ");
    scanf("%s", st);  // no & needed for char array
    paranthesis_matching(st);
    return 0;
}

