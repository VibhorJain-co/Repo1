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
    while(current ->next !=current){
        struct node * ToDelete = current->next;
        current -> next = current->next->next;
        current = current->next;
        free(ToDelete);
    }
    return current;
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
    // head = head->next;

    struct node* buffer = head;
    buffer = delete(head);
    printf("%d",buffer->val);
}