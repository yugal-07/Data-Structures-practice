#include<stdio.h>
#include<stdlib.h>
struct x{
  int data;
  struct x *next;
};
struct x *t;

void print(){
  struct x *temp=t;
  printf("Linked-List : ");
  while(temp!=NULL){
    printf("%d -> ",temp->data);
    temp=temp->next;
  }
  printf("NULL \n");
}

void insert_at_beginning(int value){
  struct x *n1=(struct x *)malloc(sizeof(struct x));
  n1->data=value;
  n1->next=t;
}

void insert_at_end(int value){
  struct x *n1=(struct x *)malloc(sizeof(struct x));
  n1->data=value;
  n1->next=NULL;
  if(t==NULL){
    t=n1;
    return;
  }
  struct x *temp=t;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n1;
}

void insert_Nth_term(int value,int pos){
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

void delete_beginning(){
    struct x *temp=t;
    t=temp->next;
    free(temp);
}

void delete_end(){
  struct x *temp=t;
  if(t==NULL){
    return;
  }
  if(temp->next==NULL){
    t=NULL;
    free(temp);
    return;
  }
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  free(temp->next);
  temp->next=NULL;
}

void delete_Nth_term(int pos){
  struct x *temp=t;
  if(t==NULL){
    return;
  }
  if(pos==1){
    free(temp);
    t=NULL;
    return;
  }
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  struct x *temp2=temp->next;
  temp->next=temp2->next;
  free(temp2);
}

void reverse(){
  struct x *current,*prev,*nex;
  current=t;
  prev=NULL;
  while(current!=NULL){
    nex=current->next;
    current->next=prev;
    prev=current;
    current=nex;
  }
  t=prev;
}

void last_to_first(){
  struct x *temp=t;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  struct x *temp2=temp->next;
  temp2->next=t;
  temp->next=NULL;
  t=temp2;
}

void search(int value){
  struct x *temp=t;
  int i=1;
  while(temp->data!=value){
    temp=temp->next;
    i++;
  }
  printf("%d found at position %d\n",value,i);
}

void find_node_value(int pos){
  struct x *temp=t;
  for(int i=1;i<pos;i++){
    temp=temp->next;
  }
  printf("%d is the value at the position %d\n",temp->data,pos);
}

void middle_element(){
  if(t==NULL){
  return;
  }
  struct x *temp=t;
  int k=0;
  while(temp!=NULL){
    temp=temp->next;
    k++;
  }
  struct x *temp2=t;
  for(int i=0;i<k/2;i++){
    temp2=temp2->next;
  }
  printf("%d\n", temp2->data);

}

void remove_duplicate(){
  struct x *temp=t;
  struct x *temp2=t;
  while(temp!=NULL){
    while(temp2->next!=NULL){
       if(temp2->next->data==temp->data){
        struct x *temp3=temp2->next;
        temp2->next=temp3->next;
        free(temp3);
      }
      else{
      temp2=temp2->next;
      }
    }
    temp=temp->next;
    temp2=temp;
  }
}

void swap(int pos,int pos2){
  struct x *temp=t;
  struct x *temp2=t;
  if(pos==pos2){
    return;
  }
  for(int i=1;i<pos;i++){
      temp=temp->next;
  }
  for(int i=1;i<pos2;i++){
      temp2=temp2->next;
  }
  if(temp==NULL||temp2==NULL){
    printf("invalid position\n");
    return;
  }
  int z=temp->data;
  temp->data=temp2->data;
  temp2->data=z;
}

void count(){
  struct x *temp=t;
  int i=1;
  while(temp->next!=NULL){
    temp=temp->next;
    i++;
  }
  printf("Total number of nodes = %d\n",i);
}

void max_min(){
  struct x *temp=t;
  int max=t->data,min=t->data;
  while(temp!=NULL){
    if(temp->data>max){
      max=temp->data;
    }
    else if(temp->data<min){
      min=temp->data;
    }
    temp=temp->next;
  }
  printf("max = %d & min = %d\n",max,min);
}

void sort(){
  struct x *temp=t;
  struct x *temp2=temp->next;
  while(temp!=NULL){
    while(temp2!=NULL){
      if(temp2->data<temp->data){
        int z=temp2->data;
        temp2->data=temp->data;
        temp->data=z;
      }
      temp2=temp2->next;
    }
    temp=temp->next;
  }
}

int main(){

  insert_at_end(10);print();
  insert_at_end(20);print();
  insert_at_end(30);print();
  insert_at_end(40);print();
  insert_at_end(50);print();
  insert_at_end(60);print();
  delete_beginning();print();
  delete_end();print();
  delete_Nth_term(2);print();
  middle_element();
  insert_at_end(100);insert_at_end(100);print();
  remove_duplicate();print();
  swap(1,2);print();
  search(100);count();
  max_min();
  sort();print();
  reverse();print();
  last_to_first();print();

  return 0;
}
