#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};
//insert
void insert(struct node** root,int value){
  struct node* n1=(struct node*)malloc(sizeof(struct node));
  n1->data=value;
  n1->left=n1->right=NULL;
  if(*root==NULL){
    *root=n1;
    return;
  }
  if((*root)->data<value){
    if((*root)->right==NULL){
      (*root)->right=n1;
      return;
    }
    insert(&(*root)->right,value);
  }
  else{
    if((*root)->left==NULL){
      (*root)->left=n1;
      return;
    }
    insert(&(*root)->left,value);
  }
}
//print level_order
struct node* arr[100];
int front=-1;
int rear=-1;
void enqueue(struct node* value){
  if(front==-1)front=0;
  arr[++rear]=value;
}
struct node *dequeue(){
  return arr[front++];
}
void level_order(struct node* root){
  if(root==NULL)return;
  enqueue(root);
  while(front<=rear){
    struct node *temp=dequeue();
    printf("%d ",temp->data);
    if(temp->left!=NULL){
    enqueue(temp->left);
    }
    if(temp->right!=NULL){
    enqueue(temp->right);
    }
  }
}
//deleting a node from binary tree
struct node* min(struct node *root){
  if(root==NULL)return 0;
  if(root->left==NULL)return root;
  return min(root->left);
}
struct node* delete(struct node* root,int value){
  if(root==NULL)return 0;
  if(root->data<value)  root->right=delete(root->right,value);        //transverse to right node
  else if(root->data>value) root->left=delete(root->left,value);      //transverse to left node
  else{
    if(root->left==NULL && root->right==NULL){      //when deleting a leaf node
      struct node* temp=root;
      root=NULL;
      free(temp);
    }
    else if(root->left==NULL){                      //when deleting a node with only right child
      struct node* temp=root;
      root=root->right;
      free(temp);
    }
    else if(root->right==NULL){                     //when deleting a node with only left child
      struct node* temp=root;
      root=root->left;
      free(temp);
    }
    else{                                           //when deleting a node with two children
      struct node* temp=min(root->right);           //we take the smallest node in the right subtree of the deleting node, and put it in place of the deleting node,
      root->data=temp->data;                        //to avoid breaking the tree.
      root->right=delete(root->right,temp->data);
    }
  }
  return root;
}
int main(){
  struct node* root=NULL;
  insert(&root,10);
  insert(&root,20);
  insert(&root,5);
  insert(&root,2);
  insert(&root,15);
  level_order(root);printf("\n");

  root = delete(root,10);

  level_order(root);printf("\n");

  return 0;
}
