//create a linked list
#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};

int main(){

	struct x *n1=(struct x*)malloc(sizeof(struct x));
	struct x *n2=(struct x*)malloc(sizeof(struct x));
	struct x *n3=(struct x*)malloc(sizeof(struct x));
	struct x *n4=(struct x*)malloc(sizeof(struct x));

	n1->data=10;
	n1->next=n2;
	n2->data=20;
	n2->next=n3;
	n3->data=30;
	n3->next=n4;
	n4->data=40;
	n4->next=NULL;
	
	while(n1!=NULL){
		printf("%d ",n1->data);
		n1=n1->next;
	}

	return 0;
}
