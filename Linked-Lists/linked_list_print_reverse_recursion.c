//print in reverse order using recursion
#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
void insert(struct x **t,int value){
//insert at the end
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=NULL;
	if(*t==NULL){
		*t=n1;
		return;
	}
	struct x *temp=*t;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	n1->next=temp->next;
	temp->next=n1;
}
void print(struct x *t){
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}
void printrev(struct x *t){
	if(t==NULL){
		return;
	}
	print(t->next);
	printf("%d ",t->data);
	
}
int main(){
	struct x *t=NULL;
	insert(&t,10);
	insert(&t,20);
	insert(&t,30);

	print(t);	
	printf("\n\n");

	printrev(t);
	
	return 0;
}
