#include<stdio.h>
#define max 10
int arr[max];
int front =-1,rear=-1;
void enqueue(int value){
	if(front==-1){
		front++;
	}
	
	rear=(rear+1)%max;
	
	arr[rear]=value;
}
void dequeue(){
	if(front==rear){
		front=rear=-1;
		return;
	}
	front=(front+1)%max;
}
void display(){
	printf("Queue: ");
	int i=front;
	while(1){
		printf("%d ",arr[i]);
		if(i==rear){
			break;
		}
		i=(i+1)%max;
	}
	printf("\n");
}
int main(){

	enqueue(10);display();
	enqueue(20);display();
	enqueue(30);display();
	enqueue(40);display();
	dequeue();display();
	dequeue();display();
	dequeue();display();
}
