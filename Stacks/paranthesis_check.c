//paranthesis check
#include<stdio.h>
#include<string.h>
#define maxx 101
int arr[maxx];
int top=-1;
void push(int value){
	arr[++top]=value;
}
void pop(){
	top--;
}
int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
void ParaCheck(char st[]){
	int len=strlen(st);
	for(int i=0;i<len;i++){
		if(st[i]=='[' ||st[i]=='{' ||st[i]=='('){
			push(st[i]);
		}
		else if((arr[top]=='{' && st[i]=='}') ||(arr[top]=='(' && st[i]==')') ||(arr[top]=='[' && st[i]==']')){
			pop();
		}
	}
	if(isempty()){
		printf("Paranthesis Balanced");
	}
	else{
		printf("Paranthesis Unbalanced");
	}
	printf("\n");
}
int main(){
	char st[maxx];
	printf("enter the equation:");
	fgets(st,maxx,stdin);

	ParaCheck(st);

	return 0;
}
