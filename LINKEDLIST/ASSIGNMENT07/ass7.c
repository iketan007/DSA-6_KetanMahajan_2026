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
        last->next = p;

    last = p;
    }
    return head;
}
s* insertHead(s* head){
    s* p = (s*)malloc(sizeof(s));

    printf("\nEnter data for new head node:\n");
    printf("Enter no name marks: ");
    scanf("%d %s %d", &p->no, p->name, &p->marks);
    p->next = head; 
    head = p;  
    
    return head;
}
void display(s* p){
    while(p != NULL){
        printf("|%d %s %d| -> ", p->no, p->name, p->marks);
        p = p->next;
    }
    printf("NULL\n");
}
int main(){
    s* start = NULL;
    start = create(start);

    printf("\nOriginal List:\n");
    display(start);

    start = insertHead(start);

    printf("\nAfter Inserting at Head:\n");
    display(start);

    return 0;
}