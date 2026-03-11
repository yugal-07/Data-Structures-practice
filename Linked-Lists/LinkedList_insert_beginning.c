#include<stdio.h>
#include<stdlib.h>

struct x{
	int data;
	struct x *next;
};
struct x *t;
void insert(int value){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=t;
	t=n1;
}

void print(){
	struct x *temp=t;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main(){
	int value,n;
	printf("HOW MANY NUMBERS WOULD YOU LIKE TO INSERT?\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	printf("ENTER A VALUE TO INSERT:");
	scanf("%d",&value);
	insert(value);
	print();
	}
	printf("\n");
	return 0;
}
