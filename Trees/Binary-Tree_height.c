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

int max(int a,int b){   //max function is made to use in height function.
  if(a>b) return a;
  else return b;
}

int height(struct node *t){
  if(t==NULL){
    return -1;
  }
  return max(height(t->right),height(t->left))+1;
}

int main(){

  insert(10);
  insert(20);
  insert(1);
  insert(100);
  printf("THE HEIGHT IS %d\n",height(root));

  return 0;
}
