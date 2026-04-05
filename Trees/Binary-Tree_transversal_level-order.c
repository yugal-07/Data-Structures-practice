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

struct node *arr[100];
int front=-1,rear=-1;     //creating a queue for level-order transversal
void enqueue(struct node *value){
  if(front==-1)front++;
  arr[++rear]=value;
}
struct node *dequeue(){
  return arr[front++];
}

//using queue to reach the previous node by using enqueue and dequeu functions
void level(struct node *root){
  if(root==NULL){
    return;
  }
  enqueue(root);
  while(front<=rear){
    struct node *temp=dequeue();      //we print the value of dequeued pointer whhose children are going to be in the loop next
    printf("%d ",temp->data);
    if(temp->left!=NULL)  enqueue(temp->left);
    if(temp->right!=NULL)  enqueue(temp->right);
  }
}
int main(){
  struct node *root=NULL;
  insert(&root,10);
  insert(&root,20);
  insert(&root,30);
  insert(&root,1);
  level(root);

  return 0;
}
