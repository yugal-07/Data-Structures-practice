//inserting a integer in an array

#include<stdio.h>

void insert(int x,int arr[]){
	for(int i=5;i>=x;i--){
		arr[i+1]=arr[i];
	}
	

}
void print(int arr[]){
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
}
int main(){

int x=2,k=102;
int arr[10]={1,2,3,4,5};

insert(x,arr);
arr[x]=k;
print(arr);

return 0;
}
