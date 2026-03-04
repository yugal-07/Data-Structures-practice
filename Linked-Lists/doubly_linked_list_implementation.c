#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
	struct x *prev;
};
struct x *t;
struct x *node(int value){
	struct x *n=(struct x *)malloc(sizeof(struct x));
	n->data=value;
	n->next=NULL;
	n->prev=NULL;
};
//insertion using head
void inserthead(int value){
	struct x *n1=node(value);
	if(t==NULL){
		t=n1;
		return;
	}
	t->prev=n1;
	n1->next=t;
	t=n1;
}
void print(){
	struct x *temp=t;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
void printrev(){
	struct x *temp2=t;
	if(temp2==NULL){
		return;
	}
	while(temp2!=NULL){
		temp2=temp2->next;
	}
	while(temp2!=NULL){
		printf("%d ",temp2->data);
		temp2=temp2->prev;
	}
}
int main(){
	inserthead(10);
	inserthead(20);
	inserthead(30);

	print();
	printf("\n");
	printrev();
	
	return 0;
}
