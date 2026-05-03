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
s* insertAtPos(s* head){
    int pos, i;
    s *p = head, *newnode;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    newnode = (s*)malloc(sizeof(s));
    printf("Enter no name marks: ");
    scanf("%d %s %d", &newnode->no, newnode->name, &newnode->marks);

    newnode->next = NULL;
    if(pos == 1){
    newnode->next = head;
    head = newnode;
    return head;
    }
    for(i = 1; i < pos-1 && p != NULL; i++){
    p = p->next;
    }

    if(p == NULL){
    printf("Invalid position\n");
    return head;
    }

    newnode->next = p->next;
    p->next = newnode;

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

    start = insertAtPos(start);

    printf("\nAfter Insertion:\n");
    display(start);

    return 0;
}