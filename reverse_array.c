//reverse an array

#include<stdio.h>

int reverse(int a[],int s){
	int temp;
	for(int i=0,j=s-1;i<j;i++,j--){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
}

int main(){

int a[]={1,2,3,4,5};
int s= sizeof(a)/sizeof(a[0]);

reverse(a,s);

	for(int i=0;i<s;i++){
		printf("%d ",a[i]);
	}
}
