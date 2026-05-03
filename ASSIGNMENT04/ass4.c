#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int no;
    char name[10];
    int marks;
    struct student* next;
} s;
s* create(s* head){
    int n, i;
    s *p, *last = NULL;
    printf("How many records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p = (s*)malloc(sizeof(s));
        printf("Enter no name marks: ");
        scanf("%d %s %d", &p->no, p->name, &p->marks);
        p->next = NULL;
        if(head == NULL)
            head = p;
        else
            last->next = p;last = p;
    }
    return head;
}
void display(s* p){
    while(p != NULL){
        printf("|%d %s %d| -> ", p->no, p->name, p->marks);
        p = p->next;
    }
    printf("NULL\n");
}
s* swapPairs(s* head){
    if(head == NULL || head->next == NULL)
        return head;

    s *prev = NULL;
    s *curr = head;

    head = head->next;
    while(curr != NULL && curr->next != NULL){
        s *next = curr->next;
        curr->next = next->next;
        next->next = curr;

        if(prev != NULL)
            prev->next = next;

        prev = curr;
        curr = curr->next;
    }
    return head;
}
int main(){
    s* start = NULL;
    start = create(start);

    printf("\nOriginal List:\n");
    display(start);

    start = swapPairs(start);

    printf("\nAfter Swapping Consecutive Nodes:\n");
    display(start);

    return 0;
}