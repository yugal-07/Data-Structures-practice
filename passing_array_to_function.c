#include<stdio.h>
void summ(int a[],int *sum){
	*sum=0;
	for(int i=0;i<5;i++){
		*sum=*sum+a[i];
	}
}
void avgg(float *avg,int sum){	
		*avg=sum/5;
}
void maxx(int a[],int *max,int *min){
	*max=a[0];
	*min=a[0];
	for(int i=0;i<5;i++){
		if(*max<a[i]){
			*max=a[i];
		}
		else if(*min>a[i]){
			*min=a[i];
		}
	}
}
void print(int sum,float avg,int max,int min){
		printf("sum=%d avg=%f max=%d min=%d \n",sum,avg,max,min);
}

int main(){
	float avg;
	int sum,max,min;
	int a[5];
	for(int i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	summ(a,&sum);
	avgg(&avg,sum);
	maxx(a,&max,&min);
	print(sum,avg,max,min);

	return 0;
}
