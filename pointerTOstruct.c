//pointer to struct

#include<stdio.h>

struct info{
	char name[20];
	int age;
};

int main(){

	struct info p1={"Yugal",18};
	struct info *p=&p1;
	printf("%s ",p->name);
	printf("%d",p->age);
printf("\n");
	return 0;
}
