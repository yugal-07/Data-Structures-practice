//postfix evaluation
#include<stdio.h>
#include<string.h>
#define max 101
int a[max];
int top=-1;
void push(int value){
	a[++top]=value;
}
int pop(){
	if(top==-1){
		return -1;
	}
	else{
		int y=a[top];
		top--;
		return y;
	}
}

int main(){

	char st[max];
	printf("Enter the equation:");
	fgets(st,max,stdin);
	int len=strlen(st);
	if(st[len-1] == '\n'){
	    st[len-1] = '\0';
	    len--;
	}
	int x;
	int z;
	int full;
	for(int i=0;i<len;i++){
		if(st[i]=='*'){
			z=pop();
			x=pop();
			full=x*z;
			push(full);
		}
		else if(st[i]=='+'){
			z=pop();
			x=pop();
			full=x+z;
			push(full);
		}
		else if(st[i]=='-'){
			z=pop();
			x=pop();
			full=x-z;
			push(full);
		}
		else if(st[i]=='/'){
			z=pop();
			x=pop();
			full=x/z;
			push(full);
		}
		else{
			push(st[i]-'0');
		}
	}
	printf("%d ",pop());
	
	return 0;
}
