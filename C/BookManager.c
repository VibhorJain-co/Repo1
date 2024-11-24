#include <stdio.h>
#include <stdlib.h>

struct node{
    char title[101];
    char author[51];
    int year;
    float rating;
    struct node * next;
};

struct node* add(struct node* head){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    scanf("%s",ptr->title);
    scanf("%s",ptr->author);
    scanf("%d",&(ptr->year));
    scanf("%f",&(ptr->rating));
    ptr->next = NULL;

    if(head == NULL){
        head = ptr;
    }else{
        struct node * current = head;
        while(current -> next != NULL){
            // printf("h1");
            current = current->next;
        }
        current -> next = ptr;
    }
    // printf("h2");
    return head;
}

int PrintList(struct node* head){
    struct node * current = head;
    while(current!= NULL){
        printf("%s ",current->title);
        printf("%s ",current->author);
        printf("%d ",(current->year));
        printf("%0.1f ",(current->rating));
        printf("\n");
        current = current->next;
    }
    return 0;
}


int main(){
    int n;
    scanf("%d",&n);
    struct node* head;
    head = NULL;

    for(int i=0;i<n;i++){
        head = add(head);
    }
    // printf("%d %d",head->year,head->next->year);
    PrintList(head);
    
    return 0;
}