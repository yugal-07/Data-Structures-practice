#include<stdio.h>
#define maxx 101
int a[maxx];
int top=-1;
void push(int value){
	top++;
	a[top]=value;
}
void pop(){
	top--;
}
void print(){
	printf("stack: ");
	for(int i=0;i<=top;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){

	push(10);print();
	push(20);print();
	push(30);print();
	pop();print();
	push(40);print();


	return 0;
}
