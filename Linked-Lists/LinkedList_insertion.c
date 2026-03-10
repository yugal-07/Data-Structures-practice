#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
struct x *t=NULL;
void insertATbeginning(int value){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=t;
	t=n1;
}
void insertNthterm(int value,int pos){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	if(pos==1){
		n1->next=t;
		t=n1;
		return;
	}
	struct x *temp=t;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	n1->next=temp->next;
	temp->next=n1;
}
void insertATend(int value){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=NULL;
	if(t==NULL){
		n1->next=t;
		t=n1;
		return;
	}
	struct x *temp=t;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n1;
}
void print(){
	struct x *tempp=t;
	printf("Linked List: ");
	while(tempp!=NULL){
		printf("%d ",tempp->data);
		tempp=tempp->next;
	}
	printf("\n");
}
int main(){

	insertATend(10);
	insertATend(20);
	insertATend(30);
	print();
	insertATbeginning(100);
	print();
	insertNthterm(200,2);
	print();
	return 0;
}
