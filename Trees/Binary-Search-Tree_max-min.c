//max-min in binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root;
void insert(int value){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data=value;
  n1->left=n1->right=NULL;
  if(root==NULL){
    root=n1;
    return;
  }
  struct node *temp=root;
  while(temp!=NULL){
    if(value>temp->data){
      if(temp->right==NULL){
        temp->right=n1;
        return;
      }
      temp=temp->right;
    }
    else{
      if(temp->left==NULL){
        temp->left=n1;
        return;
      }
      temp=temp->left;
    }
  }
}
//right most element is the largest
//leftmost element is the smallest
void maxmin(){
  struct node *temp=root;
  while(temp->right!=NULL){
    temp=temp->right;
  }
  printf("max =%d ",temp->data);
  struct node *temp2=root;
  while(temp2->left!=NULL){
    temp2=temp2->left;
  }
  printf("min = %d ",temp2->data);
}
int main(){

  insert(10);
  insert(20);
  insert(1);
  insert(100);
  maxmin();

  return 0;
}
