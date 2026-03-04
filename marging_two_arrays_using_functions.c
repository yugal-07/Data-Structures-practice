#include<stdio.h>

void merge(int a[],int b[],int c[],int n,int m){

	for(int i=0;i<n;i++){
		c[i]=a[i];
	}
	for(int i=0;i<m;i++){
			c[i+n]=b[i];
		}
}
void print(int n,int m,int c[]){
	for(int i=0;i<n+m;i++){
		printf("%d ",c[i]);
	}
}
int main(){
	int m,n;
	int a[]={1,2,3};	
	int b[]={1,2,3};
	
	n=sizeof(a)/sizeof(a[0]);
	m=sizeof(b)/sizeof(b[0]);
	int c[m+n];

	merge(a,b,c,n,m);
	print(n,m,c);

	return 0;
}
