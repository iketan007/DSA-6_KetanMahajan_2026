#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int no;
    char name[10];
    int marks;
    struct student* next;
} s;

s* create(s* head){
    s* last = NULL;
    int n, i;
    printf("How many records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        s* p = (s*)malloc(sizeof(s));
        printf("\nEnter no name marks: ");
        scanf("%d %s %d", &p->no, p->name, &p->marks);

        p->next = NULL;
        if(head == NULL){
            head = p;
        }
        else{
            last->next = p;
        }
        last = p;
    }
    return head;
}
void alternatedisp(s* p){
    if(!p){
        printf("List is not created");
        return;
    }
    while(p != NULL){
        printf("|%d %s %d|", p->no, p->name, p->marks);

        if(p->next == NULL || p->next->next == NULL){
            break;
        }
        printf(" -> ");
        p = p->next->next;
    }
    printf(" -> NULL");
}

int main(){
    s* start = NULL;
    start = create(start);

    printf("\nAlternate Nodes:\n");
    alternatedisp(start);

    return 0;
}