#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void Insert(int x) {
    struct Node* temp1 = malloc(sizeof(struct Node*));
    temp1->data = x;
    temp1->next = NULL;
    if(head == NULL) {
        head = temp1;
        return;
    }
    struct Node* temp2 = malloc(sizeof(struct Node*));
    while(temp2 != NULL) {
        temp2->next = temp1;
    }
}

void Print() {
    struct Node* temp = malloc(sizeof(struct Node*));
    temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main()
{
    head = NULL;
    Insert(5);
    Insert(4);
    Insert(3);
    Print();
    return 0;
}
