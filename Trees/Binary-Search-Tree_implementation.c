#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct x{
  int data;
  struct x *left;
  struct x *right;
};
struct x *t;
void insert(int value){
  struct x *n1=(struct x *)malloc(sizeof(struct x));
  n1->data=value;
  n1->left=NULL;
  n1->right=NULL;

  if(t==NULL){
    t=n1;
    return;
  }
  struct x *temp=t;
  while(temp!=NULL){
    if(n1->data>temp->data){
      if(temp->right==NULL){
        temp->right=n1;
        return;
      }
      temp=temp->right;
    }
    else {
      if(temp->left==NULL){
        temp->left=n1;
        return;
      }
      temp=temp->left;
    }
  }
}
//create a search function  --DONE
//also, try to create insert and search using recursion
bool search(int value){
  struct x *temp=t;
  while(temp!=NULL){
    if(temp->data==value){
      return 1;
    }
    if(value>temp->data){
      temp=temp->right;
    }
    else{
      temp=temp->left;
    }
  }
  return 0;
}
int main(){
  insert(10);
  insert(20);
  insert(30);
  int value;
  scanf("%d",&value);

  if(search(value)){
    printf("found");
  }
  else{
    printf("Not found");
  }
  printf("\n");
  return 0;
}
