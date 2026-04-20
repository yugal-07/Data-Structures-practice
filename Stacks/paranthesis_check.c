//stack ADT and paranthesis matching
#include <stdio.h>
#include <string.h>
#define max 101
int arr[max];
int top=-1;
void push(int value){
  arr[++top]=value;
}
void pop(){
  top--;
}
int isempty(){
  if(top==-1)return 1;
  return 0;
}
void paranthesis_matching(char st[]){
  int len=strlen(st);
  for(int i=0;i<len;i++){
    if(st[i]=='[' || st[i]=='(' || st[i]=='{'){
      push(st[i]);
    }
    else if(st[i]=='}' && arr[top]=='{' ||
            st[i]==')' && arr[top]=='(' ||
            st[i]==']' && arr[top]=='[' ){
      pop();
    }
    else if(st[i]==']' || st[i]==')' || st[i]=='}'){
      push(st[i]);
    }
  }
  if(isempty()){
    printf("paranthesis balanced\n");
  }
  else{
    printf("paranthesis unbalanced\n");
  }
}
int main(){
  char st[20];
  printf("Enter the equation:");
  scanf("%s",&st);
  paranthesis_matching(st);

  return 0;
}

