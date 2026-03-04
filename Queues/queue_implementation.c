#include<stdio.h>
#define max 10
int arr[max];
int front =-1,rear=-1;
void enqueue(int value){
	if(front==-1){
	front++;
	}
	if(rear==9){
		printf("Queue Overflow");
		return;
	}
	arr[++rear]=value;
}
void dequeue(){
	front ++;
	if(front>rear){
		front=rear=-1;
	}
}
void display(){
	printf("Queue: ");
	for(int i=front;i<=rear;i++){
		printf("%d ",arr[i]);
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
