#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define M 10
#define CLUSTER_SIZE 1000

struct Node{
    unsigned int cluster_number;
    unsigned int next_cluster;

    unsigned int bytes_filled;

    struct Node* next;
};

// ############################## DO NOT MODIFY THE CODE ABOVE THIS LINE ##############################

// You can add your helper functions here, or global variables, structs etc if you require
int cluster_count=0;
struct Node* add(struct Node*head, unsigned long file_number, unsigned long bytes_to_append){

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->cluster_number = cluster_count;
    cluster_count++;
    ptr->next_cluster = -1;
    ptr->bytes_filled = bytes_to_append;
    ptr->next = NULL;
    
    if(head==NULL){
        head = ptr;
    }else{
        struct Node* current = head;
        while(current->next!=NULL){
            current = current->next;
        }
        current -> next = ptr;
        current->next_cluster = ptr->cluster_number;
    }
    return head;
}

void append(unsigned long file_number, unsigned long bytes_to_append, struct Node* file_heads[]){
    struct Node* head = file_heads[file_number];
    struct Node* current = head;
    int modified=0;
    
    if(head==NULL){
        head = add(head,file_number,bytes_to_append);
        file_heads[file_number] = head;
    }else{
        while(current->next!=NULL){
            current = current->next;
        }
        if(current->bytes_filled +bytes_to_append<=1000){
            current->bytes_filled += bytes_to_append;
        }else{
            head = add(head,file_number,bytes_to_append);
        }
        
    }
    
}

void update(unsigned long cluster_number, struct Node* file_heads[]){
    for(int i=0;i<10;i++){
        struct Node* head = file_heads[i];
        struct Node* current = head;
        while(current!=NULL){
            if((current->cluster_number)>cluster_number){
                current->cluster_number -=1;
            }
            current= current->next;
        }
    }
}

void delete(unsigned long file_number, unsigned long cluster_number, struct Node* file_heads[]){
    struct Node* head = file_heads[file_number];
    struct Node* current = head;
    if(head->cluster_number == cluster_number){
        head = head -> next;
        
    }else{
        while(current->next->cluster_number != cluster_number){
            current = current->next;
        }
        current->next = current->next->next;
    }
    
    update(cluster_number,file_heads);
    cluster_count--;
    
    file_heads[file_number] = head;
}

// ############################## DO NOT MODIFY THE CODE BELOW THIS LINE ##############################

int main(){
    struct Node* file_heads[M];
    for(int i = 0; i < M; i++){
        file_heads[i] = NULL;
    }

    int q;
    scanf("%d", &q);

    for(int qq = 0; qq < q; qq++){
        int type;
        scanf("%d", &type);

        if(type == 1){
            unsigned long file_number, bytes_to_append;
            scanf("%lu %lu", &file_number, &bytes_to_append);
            append(file_number, bytes_to_append, file_heads);
        }
        else{
            unsigned long file_number, cluster_number;
            scanf("%lu %lu", &file_number, &cluster_number);
            delete(file_number, cluster_number, file_heads);
        }
    }

    for(int i = 0; i < M; i++){
        struct Node* head = file_heads[i];
        while(head != NULL){
            printf("%lu %lu %lu\n", head->cluster_number, head->next_cluster, head->bytes_filled);
            head = head->next;
        }
        printf("-1\n");
    }

    for(int i = 0; i < M; i++){
        struct Node* head = file_heads[i];
        while(head != NULL){
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
    }

    return 0;
}