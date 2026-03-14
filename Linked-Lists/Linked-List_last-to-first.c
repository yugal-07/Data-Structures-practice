#include <stdio.h>
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
void change(){
    struct x *temp=t;
    struct x *temp2=t;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    while(temp2->next!=temp){
      temp2=temp2->next;
    }
    temp->next=t;
    temp2->next=NULL;
    t=temp;
}
void print(){
    struct x *temp=t;
    printf("Linked List: ");
  while(temp!=NULL){
      printf("%d -> ",temp->data);
        temp=temp->next;
  }
  printf("NULL\n");
}

int main(){
  insert(10);print();
  insert(20);print();
  insert(30);print();
  insert(40);print();
  change();print();

  return 0;
}
