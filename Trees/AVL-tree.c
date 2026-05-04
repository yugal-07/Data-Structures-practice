#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node *left;
  struct node *right;
  int height;
}node;
node *create(int value){
  node* n1=(node *)malloc(sizeof(node));
  n1->data=value;
  n1->left=NULL;
  n1->right=NULL;
  n1->height=0;
  return n1;
}
//functions made to use in other functions
int max(int a,int b){
  if(a>b)return a;
  return b;
}
int min(node *root){
  if(root->left==NULL)return root->data;
  return min(root->left);
}
//
//height of tree 
int height(node *root){
  if(root==NULL)return -1;
  return root->height;
}
void update_height(node *root){
  if(root==NULL)return ;
  root->height = max(height(root->left),height(root->right))+1;
}
//
//balance factor
int balance_factor(node *root){
  if(root==NULL)return 0;
  return height(root->left) - height(root->right);
}
//
//left and right rotation
node *right_rotation(node *root){
  node *temp=root->left;
  node *temp2=temp->right;
  temp->right=root;
  root->left=temp2;
  update_height(root);          //height needs to be updated for both the nodes as they are rotated
  update_height(temp);
  return temp;
}
node *left_rotation(node *root){
  node *temp=root->right;
  node *temp2=temp->left;
  temp->left=root;
  root->right=temp2;
  update_height(root);          //height needs to be updated for both the nodes as they are rotated
  update_height(temp);
  return temp;
}
//
//AVL insertion
node *insert(node* root,int value){
  if(root==NULL){
    node *n1=create(value);
    return n1;
  }
  if(value>root->data){                                             //same insertion as BST
    root->right=insert(root->right,value);
  }
  else{
    root->left=insert(root->left,value);
  }
  update_height(root);
  if(balance_factor(root)>1 && value<root->left->data){             //but is then checked with the AVL conditions to rotate.
    return right_rotation(root);
  }
  else if(balance_factor(root)< -1 && value>root->right->data){
    return left_rotation(root);
  }
  else if(balance_factor(root)>1 && value>root->left->data){
    root->left=left_rotation(root->left);
    return right_rotation(root);
  }
  else if(balance_factor(root)< -1 && value<root->right->data){
    root->right=right_rotation(root->right);
    return left_rotation(root);
  }
  return root;
}
//
//AVL deletion
node *delete(node *root,int value){
  if(root==NULL)return NULL;
  if(value>root->data){                                             //same deletion as BST
    root->right=delete(root->right,value);
  }
  else if(value<root->data){
    root->left=delete(root->left,value);
  }
  else{
    if(root->left==NULL && root->right==NULL){
      node *temp=root;
      root=NULL;
      free(temp);
    }
    else if(root->right==NULL){
      node *temp=root;
      root=temp->left;
      free(temp);
    }
    else if(root->left==NULL){
      node *temp=root;
      root=temp->right;
      free(temp);
    }
    else{
      int temp=min(root->right);
      root->data=temp;
      root->right=delete(root->right,temp);
    }
  }
  update_height(root);
  if(balance_factor(root)>1 && balance_factor(root->left)>=0){         //but is then checked with the AVL conditions to rotate.
    return right_rotation(root);
  }
  else if(balance_factor(root)>1 && balance_factor(root->left)<0){
    root->left=left_rotation(root->left);
    return right_rotation(root);
  }
  else if(balance_factor(root)< -1 && balance_factor(root->right)<0){
    return left_rotation(root);
  }
  else if(balance_factor(root)< -1 && balance_factor(root->right)>=0){
    root->right=right_rotation(root->right);
    return left_rotation(root);
  }
  return root;
}
//
//inorder transversal
void inorder(node *root){
  if(root==NULL)return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
//
//level order transversal
//queue for level order transversal
#define maxx 20
node* arr[maxx];
int front=-1;
int rear=-1;
void enqueue(node* value){
  if(front==-1)front++;
  arr[++rear]=value;
}
node* dequeue(){
  return arr[front++];
}
//
void level_order(node *root){
  if(root==NULL)return;
  front=-1;rear=-1;
  enqueue(root);
  while(front<=rear){
    node *temp=dequeue();
    printf("%d ",temp->data);
    if(temp->left!=NULL)  enqueue(temp->left);
    if(temp->right!=NULL) enqueue(temp->right);
  }
}
//
int main(){
  node *root=NULL;
  root=insert(root,10);
  root=insert(root,20);
  root=insert(root,30);
  root=insert(root,40);
  root=insert(root,50);
  level_order(root);printf("\n");
  root=delete(root,20);
  level_order(root);
  return 0;
}
