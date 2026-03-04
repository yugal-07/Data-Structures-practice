//insert at end position
#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
void insert(int value,struct x **t){
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
int main(){
	struct x *t=NULL;
	insert(10,&t);
	insert(20,&t);
	insert(30,&t);
	print(t);
	return 0;
}
