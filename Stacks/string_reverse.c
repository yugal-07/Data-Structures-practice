//reversing a string using stack
#include<stdio.h>
#include<string.h>
#define maxx 101
int a[maxx];
int top=-1;
void push(int value){
	if(top==maxx-1){
		printf("stack overflowed\n");
		return;
	}
	top++;
	a[top]=value;
}
int pop(){
	if(top==-1){
		printf("No entries to pop");
		return -1;
	}
	int x=a[top];
	top--;
	return x;
}
void reverse(int len,char st[]){
	for(int i=0;i<len;i++){
		push(st[i]);
	}
	for(int i=0;i<len;i++){
		st[i]=pop();
	}
}
int main(){
	char st[maxx];
	printf("Enter the contents of string:");
	fgets(st,sizeof(st),stdin);

	reverse(strlen(st),st);
	printf("%s ",st);

	return 0;
}
