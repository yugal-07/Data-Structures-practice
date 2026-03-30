#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root;
void insert(int value){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data=value;
  n1->left=NULL;
  n1->right=NULL;
  if(root==NULL){
    root=n1;
    return;
  }
  struct node *temp=root;
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
bool search(int value){
  struct node *temp=root;
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
