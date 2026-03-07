//insert nth term in linked list
#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
struct x *t;
void insert(int value,int pos){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=NULL;
	if(pos==1){
		n1->next=t;
		t=n1;
		return;
	}
	struct x *temp=t;
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
		if(temp==NULL){
			printf("too far from the list");
			return ;
		}
	}	
	n1->next=temp->next;
	temp->next=n1;
}
void print(){
	struct x *temp=t;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main(){
	insert(10,1);
	insert(20,1);
	insert(30,1);
	insert(40,1);
	insert(100,3);
	print();
	
}
