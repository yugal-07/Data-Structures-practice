#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_nth(int value, int pos){

    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    for(int i = 1; i < pos-1; i++){
        temp = temp->next;

        if(temp == NULL){
            printf("Position out of range\n");
            return;
        }
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void print(){
    struct node* temp = head;

    printf("List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    insert_nth(10,1);
    insert_nth(20,2);
    insert_nth(30,3);

    print();

    insert_nth(15,2);

    printf("After inserting at position 2:\n");
    print();

    return 0;
}
