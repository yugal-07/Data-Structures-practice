#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
  struct node *prev;
};
struct node *head;
void print(){
  struct node *temp=head;
  printf("Linked List: ");
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}
void insert_AT_beginning(int value){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data=value;
  if(head==NULL){
    n1->next=n1->prev=NULL;
    head=n1;
    return;
  }
  n1->prev=NULL;
  n1->next=head;
  head=n1;
}
void insert_Nth_term(int value,int pos){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data = value;
  if(pos==1){
    insert_AT_beginning(value);
    return;
  }
  struct node *temp=head;
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  n1->next=temp->next;
  temp->next->prev=n1;
  temp->next=n1;
  n1->prev=temp;
}
void insert_AT_end(int value){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data=value;
  if(head==NULL){
    insert_AT_beginning(value);
    return;
  }
  struct node *temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n1;
  n1->prev=temp;
  n1->next=NULL;
}
void length(){
  struct node *temp=head;
  int i=0;
  while(temp!=NULL){
    temp=temp->next;
    i++;
  }
  printf("The length is %d node(s)\n",i);
}
void delete_AT_beginning(){
  struct node *temp=head;
  head=temp->next;
  head->prev=NULL;
  free(temp);
}
void delete_Nth_term(int pos){
  struct node *temp=head;
  if(pos==1){
    delete_AT_beginning();
    return;
  }
  for(int i=1;i<pos-1;i++){
    temp=temp->next;
  }
  struct node *temp2=temp->next;
  temp->next=temp2->next;
  temp2->next->prev=temp;
  free(temp2);
}
void delete_AT_end(){
  struct node *temp=head;
  if(head==NULL){
    printf("List is empty");
    return;
  }
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  struct node *temp2=temp->next;
  temp->next=NULL;
  free(temp2);
}
int main(){
  insert_AT_beginning(10);print();
  insert_AT_beginning(20);print();
  insert_Nth_term(30,2);print();
  insert_AT_end(40);print();
  length();
  delete_AT_beginning();print();
  delete_Nth_term(2);print();
  delete_AT_end();print();
  length();
  return 0;
}
