//BST insert, delete , inorder successor, max, min, inorder
#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node* insert(struct node *root,int value){
  struct node *n1=(struct node*)malloc(sizeof(struct node));
  n1->data=value;
  n1->left=n1->right=NULL;
  if(root==NULL){
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
void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
//inorder_successor
struct node *find_min_node(struct node *root){
  if(root->left==NULL){
    return root;
  }
  return find_min_node(root->left);
}
struct node* inorder_successor(struct node *root,int value){
  struct node *successor=NULL;
  while(root!=NULL){
    if(value>root->data){
      root=root->right;
    }
    else if(value<root->data){
      successor=root;
      root=root->left;
    }
    else{
      if(root->right!=NULL){
        successor=find_min_node(root->right);
      }
      break;
    }
  }
  return successor;
}

int main(){
  struct node *root=NULL;
  root=insert(root,10);
  root=insert(root,20);
  root=insert(root,30);
  root=insert(root,5);
  inorder(root);printf("\n");
  printf("%d \n",inorder_successor(root,5)->data);
  return 0;
}
