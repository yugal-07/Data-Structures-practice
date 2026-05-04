//priority queue
#include <stdio.h>
#include <stdlib.h>
struct element{
  int data;
  int priority;
};
struct queue{
  int size;
  int capacity;
  struct element *arr;
};
struct queue *q;
void create(int value){
  q=(struct queue*)malloc(sizeof(struct queue));
  q->size=0;
  q->capacity=value;
  q->arr=(struct element*)malloc(value*sizeof(struct element));
}
void insert(int value,int priority){
  if(q->size==q->capacity){
    printf("Full");
    return;
  }
  q->arr[q->size].data=value;
  q->arr[q->size].priority=priority;
  q->size++;
}
int isempty(){
  if(q->size==0){
    return 1;
  }
  return 0;
}
int isfull(){
  if(q->size==q->capacity){
    return 1;
  }
  return 0;
}
void print(){
  for(int i=0;i<q->size;i++){
    printf("%d(%d) ",q->arr[i].data,q->arr[i].priority);
  }printf("\n");
}
void delete(){
  int highest=0;
  for(int i=1;i<q->size;i++){
    if(q->arr[i].priority>q->arr[highest].priority){
      highest=i;
    }
  }
  for(int i=highest;i<q->size-1;i++){
    q->arr[i]=q->arr[i+1];
  }
  (q->size)--;
}
int main(){
  create(10);
  insert(10,1);
  insert(20,2);
  print();
  delete();
  print();

  return 0;
}
