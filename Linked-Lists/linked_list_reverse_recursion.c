#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
struct x *t;
void insert(int value){
	//end
	struct x *n1=(struct x*)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=NULL;
	if(t==NULL){
		t=n1;
		return;
	}
	struct x *temp=t;
	while(temp->next!=0){
		temp=temp->next;
	}
	n1->next=temp->next;
	temp->next=n1;
}
void reverse(){
	struct x *current,*pre,*nex;
	current=t;
	pre=NULL;
	while(current!=NULL){
		nex=current->next;
		current->next=pre;
		pre=current;
		current=nex;
	}
	t=pre;	
}
void print(){
struct x *tempp=t;	//because *t is a global variable , and it should not be affected by print
	while(tempp!=NULL){
		printf("%d ",tempp->data);
		tempp=tempp->next;
	}
}
int main(){
	insert(10);
	insert(20);
	insert(30);

	print();
	printf("\n\n");

	reverse();
	print();

	return 0;
}
