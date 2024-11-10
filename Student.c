#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode*next;
}ListNode;

ListNode* input(int value,ListNode* head){
    ListNode*newnode1 = (ListNode*)malloc(sizeof(int)+8);
    scanf("%d",&(newnode1 -> val));
    newnode1 -> next = head;
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
    head = input(1,head);
    head = input(2,head);
    head = input(3,head);
    head = input(4,head);
    head = input(5,head);

    PrintList(head);
    return 0;
}