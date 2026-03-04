#include<stdio.h>
#include<stdlib.h>

struct x{
	int data;
	struct x *next;
};

void insert(int value, struct x **t){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=*t;
	*t=n1;
}

void print(struct x *t){
	while(t!=NULL){
		printf("%d -> ",t->data);
		t=t->next;
	}
	printf("\n");
}

int main(){
	struct x *t=NULL;
	int value,n;
	printf("HOW MANY NUMBERS WOULD YOU LIKE TO INSERT?\n");
	scanf("%d",&n);
for(int i=0;i<n;i++){
	printf("ENTER A VALUE TO INSERT:");
	scanf("%d",&value);
	insert(value,&t);
	print(t);
	}
	printf("\n");
	return 0;
}
