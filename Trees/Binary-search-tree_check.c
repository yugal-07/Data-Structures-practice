
//checking if a binary tree is a binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

int check(struct node *root,int min,int max){
  if(root==NULL)return 1;
  if(root->data>max || root->data<=min){
    return 0;
  }

  return check(root->left,min,root->data) && check(root->right,root->data,max);
}

int main(){
  insert(10);
  insert(20);
  insert(1);
  insert(30);
  root->left->data =50;     //comment this line to make it binary search tree
  if(check(root,INT_MIN,INT_MAX)){
    printf("IT IS A BINARY SEARCH TREE");
  }
  else{
    printf("IT IS NOT A BINARY SEARCH TREE");
  }

  printf("\n");
  return 0;
}
