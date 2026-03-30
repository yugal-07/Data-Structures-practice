//BST using recursion
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *insert(struct node *root,int value){
  if(root==NULL){
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    n1->data=value;
    n1->left=n1->right=NULL;
    return n1;
  }
  if(value>root->data){
    root->right=insert(root->right,value);
  }
  else{
    root->left=insert(root->left,value);
  }
  return root;
}
int search(struct node *root,int value){
  if(root==NULL){
    return 0;
  }
  if(value>root->data){
    return search(root->right,value);
  }
  else if(value==root->data){
    return 1;
  }
  else{
    return search(root->left,value);
  }
}
int main(){
  struct node *root=NULL;
  root= insert(root,10);
  root=insert(root,20);
  root=insert(root,30);

  int value;
  scanf("%d",&value);
  if(search(root,value)){
    printf("Found\n");
  }
  else{
    printf("Not Found\n");
  }

  return 0;
}
