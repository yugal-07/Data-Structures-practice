//without string.h
#include<stdio.h>
#include<ctype.h>
#define max 101
int arr[max];
int top=-1;
void push(int value){
	if(top==100){
		printf("stack overflowed\n");
		return;
	}
	arr[++top]=value;
}
int pop(){
	if(top==-1){
		printf("stack is empty");
		return -1;
	}
	int temp=arr[top];
	top--;
	return temp;
}
int priority(char x){
	if(x=='('){
		return 0;
	}
	else if(x=='+'||x=='-'){
		return 1;
	}
	else if(x=='*'||x=='/'){
		return 3;
	}
	else if(x=='^'){
		return 4;
	}
}

int main(){
	char infix[max],postfix[max];
	scanf("%s",infix);
	int i=0,j=0;
	while(infix[i]!='\0'){
		if(isalnum(infix[i])){
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='('){
			push(infix[i]);
		}
		else if(infix[i]==')'){
			while(arr[top]!='('){
				postfix[j++]=pop();
			}
			pop();
		}
		else{
			while( priority(arr[top])>=priority(infix[i]) ){
				postfix[j++]=pop();
			}
			push(infix[i]);
		}
		i++;
	}
	while(top!=-1){
		postfix[j++]=pop();
	}
	postfix[j]='\0';  //just in case to give an end to the string
	printf("%s ",postfix);

	return 0;
}
