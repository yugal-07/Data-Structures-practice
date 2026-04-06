//create all types of tree transversal
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *right;
  struct node *left;
};
void insert(struct node **root,int value){
  if(*root==NULL){
    struct node *n1=(struct node *)malloc(sizeof(struct node));
    n1->data=value;
    n1->left=n1->right=NULL;
    *root=n1;
    return;
  }
  if((*root)->data<value){
    insert(&(*root)->right,value);
  }
  else{
    insert(&(*root)->left,value);
  }
}

//depth-first transversal 
void preorder(struct node *root){
  if(root==NULL){
  return;
  }
  printf("%d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct node *root){
  if(root==NULL)  return;
  inorder(root->left);
  printf("%d ",root->data);
  inorder(root->right);
}
void postorder(struct node *root){
  if(root==NULL)  return;
  inorder(root->left);
  inorder(root->right);
  printf("%d ",root->data);
}

//breadth-first transversal
struct node *arr[100];      //creating a queue for level-order transversal
int front=-1,rear=-1;
void enqueue(struct node *value){
  if(front==-1)  front++;
  arr[++rear]=value;
}
struct node *dequeue(){
  return arr[front++];
}

void level(struct node *root){
  if(root==NULL)  return;
  enqueue(root);
  while(front<=rear){
    struct node *temp=dequeue();      //the values are only printed when they are passed through the queue.
    printf("%d ",temp->data);        //each and every node has passed through the queue atleast once.
                                    //so here we enqueue both the left and right nodes if it exists.
    if(temp->left!=NULL){
      enqueue(temp->left);
    }
    if(temp->right!=NULL){
      enqueue(temp->right);
    }
  }
}

int main(){
  struct node *root=NULL;
  insert(&root,10);
  insert(&root,20);
  insert(&root,1);
  insert(&root,2);
  insert(&root,-1);
  insert(&root,30);

  preorder(root);printf("\n");
  inorder(root);printf("\n");
  postorder(root);printf("\n");

  level(root);printf("\n");
  return 0;
}
