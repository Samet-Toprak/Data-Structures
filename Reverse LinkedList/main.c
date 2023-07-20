#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;
struct node* head;

void Insert(int data) {
    node* temp =(node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    }
    else
    {
        node* ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }

}

void Print() {
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void Delete(int n) {
    node* temp1 = head;
    if(n == 1) {
        head = temp1->next;
        free(temp1);
        return;
    }

    for(int i = 0; i < n - 2; i++){
        temp1 = temp1->next;
    }
    node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void Reverse() {
    node* prev, *current, *next;
    prev = NULL;
    current = head;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = NULL;
    int position;
    Insert(5);
    Insert(2);
    Insert(9);
    Insert(12);
    Print();
    printf("\nWhich position do you want to delete? ");
    scanf("%d",&position);
    printf("\n");
    Delete(position);
    printf("After deleting %d. node:\n", position);
    Print();
    Reverse();
    printf("\nAfter reverse:\n");
    Print();
    return 0;
}
