#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode*next;
}ListNode;

ListNode* input(){
    ListNode*newnode1 = (ListNode*)malloc(sizeof(int)+8);
    scanf("%d",&(newnode1 -> val));
    newnode1 -> next = NULL;

    return newnode1;
}

int PrintList(ListNode*head){
    ListNode* current = head;
    while(current != NULL){
        printf("%d\n",current ->val);
        current = current->next;
    }
    return 0;
}

int main(){
    ListNode* head = NULL;
    ListNode* buffer = head;
    ListNode* last = head;
    head = input();
    buffer = head;
    last = input();
    buffer -> next = last;
    buffer = last;
    last = input();
    buffer -> next = last;
    buffer = last;
    last = input();
    buffer -> next = last;
    buffer = last;
    last = input();
    buffer -> next = last;
    buffer = last;

    PrintList(head);
    return 0;
}