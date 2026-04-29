#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int no;
    char name[20];
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
void display(s* p){
    while(p != NULL){
    printf("|%d %s %d| -> ", p->no, p->name, p->marks);
    p = p->next;
    }
    printf("NULL\n");
}
void addConsecutive(s* head){
    s* p = head;
    while(p != NULL && p->next != NULL){
    s* q = p->next;
    s* newnode = (s*)malloc(sizeof(s));
    newnode->no = p->no + q->no;
    newnode->marks = p->marks + q->marks;
    strcpy(newnode->name, p->name);
    strcat(newnode->name, q->name);
    newnode->next = q->next;
    q->next = newnode;

    p = newnode->next; 
    }
}
int main(){
    s* start = NULL;
    start = create(start);

    printf("\nOriginal List:\n");
    display(start);

    addConsecutive(start);

    printf("\nAfter Adding Consecutive Nodes:\n");
    display(start);

    return 0;
}