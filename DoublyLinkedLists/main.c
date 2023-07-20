#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

void insertBeginning(int x) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    if(head == NULL) {
        temp->next = head;
        temp->prev = head;
        head = temp;
        return;
    }
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertTail(int x) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head == NULL) {
        temp->prev = NULL;
        head = temp;
        return;
    }

    struct Node *temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
    temp->prev = temp2;
}

void Print() {
    struct Node *temp = malloc(sizeof(struct Node));
    temp = head;
    if(head == NULL){
        printf("List is empty!");
        return;
       }
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reversePrint(){
    struct Node *temp = head;
    if(head == NULL) {
        printf("List is empty!");
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    insertBeginning(4);
    insertBeginning(3);
    insertBeginning(2);
    insertBeginning(1);
    insertTail(5);
    insertTail(6);
    Print();
    reversePrint();
    return 0;
}
