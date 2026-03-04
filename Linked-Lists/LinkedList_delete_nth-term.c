#include<stdio.h>
#include<stdlib.h>
struct x{
	int data;
	struct x *next;
};
void insert(int value,struct x **t){
	struct x *n1=(struct x *)malloc(sizeof(struct x));
	n1->data=value;
	n1->next=*t;
	*t=n1;
}
void delete(int pos,struct x **t){
	struct x *temp=*t;
	if(pos==1){
		*t=temp->next;
		free(temp);
		return;
	}
	for(int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	struct x *temp2=temp->next;
	temp->next=temp2->next;
	free(temp2);
}
void print(struct x *t){
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->next;
	}
}
int main(){

	struct x *t=NULL;
	insert(20,&t);
	insert(10,&t);
	print(t);
	printf("\n");
	delete(2,&t);
    print(t);

	return 0;
}
