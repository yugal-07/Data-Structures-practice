//reverse of linked list
#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
void insert(struct x **t,int value){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=*t;
	*t=n1;
}

void reverse(struct x **t){
	struct x *current,*prev,*nex;
	current=*t;
	prev=NULL;
	while(current!=NULL){
		nex=current->next;
		current->next=prev;
		prev=current;
		current=nex;
	}
	*t=prev;
}

void print(struct x *t){
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}
int main(){
	struct x *t =NULL;

	insert(&t,10);
	insert(&t,20);
	insert(&t,30);

	print(t);
	printf("\n\n");
	
	reverse(&t);

	print(t);
	
	return 0;
}
