#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node * next;
};

struct node * add(int value, struct node * head){
    // printf("h1");
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->val = value;
    ptr->next = NULL;

    if(head == NULL){
        head = ptr;
    }else{
        struct node * current = head;
        while(current -> next != NULL){
            current = current->next;
        }
        current -> next = ptr;
    }
    return head;

}

struct node * connect(struct node * head){
    struct node * current = head;
        while(current -> next != NULL){
            current = current->next;
        }
        current -> next = head;

        return head;
}

struct node * delete(struct node * head){
    struct node * current = head;
    if(current ->next ==current){
        return NULL;
    }
    while(current -> next != head){
        current = current->next;
    }
    current -> next = head->next;
    free(head);
    return current->next->next;
}

int main(){
    struct node*head;
    head = NULL;
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        head = add(i,head);
        // printf("HELLO\n");
    }
    connect(head);
    // printf("HELLO");
    if(n==1){
        printf("1");
        return 0;
    }
    head = head->next;

    struct node* buffer = head;
    while(head!= NULL){
    buffer = head;
    head = delete(head);
    }

    printf("%d",buffer->val);
}