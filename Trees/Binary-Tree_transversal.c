#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
void insert(struct node **root,int value){
  struct node *n1=(struct node *)malloc(sizeof(struct node));
  n1->data=value;
  n1->left=n1->right=NULL;
  if(*root==NULL){
    *root=n1;
    return;
  }
  struct node *temp=*root;
  while(temp!=NULL){
    if(temp->data<value){
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
//transversal in preorder ,postorder and inorder in a binary tree , using recursion.
void preorder(struct node *root){
  if(root==NULL){
    return;
  }
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void postorder(struct node *root){
  if(root==NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ",root->data);
}
int main(){
  struct node *root=NULL;
  insert(&root,10);
  insert(&root,20);
  insert(&root,30);
  insert(&root,1);

  preorder(root);printf("\n");
  inorder(root);printf("\n");
  postorder(root);printf("\n");


return 0;
}
