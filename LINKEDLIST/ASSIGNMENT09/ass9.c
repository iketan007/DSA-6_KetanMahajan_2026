#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int no, marks;
    char name[10];
    struct student* next;
} s;
s* create(){
    int n;
    printf("How many records: ");
    scanf("%d",&n);
    s *head=NULL,*last=NULL,*p;

    while(n--){
    p=(s*)malloc(sizeof(s));
    scanf("%d %s %d",&p->no,p->name,&p->marks);
    p->next=NULL;

    if(!head) head=p;
    else last->next=p;

    last=p;
    }
    return head;
}
s* insertLast(s* head){
    s *p=head,*newnode=(s*)malloc(sizeof(s));

    printf("Enter no name marks: ");
    scanf("%d %s %d",&newnode->no,newnode->name,&newnode->marks);
    newnode->next=NULL;
    if(!head) return newnode;

    while(p->next) p=p->next;  
    p->next=newnode;
    return head;
}
void display(s* p){
    while(p){
    printf("|%d %s %d| -> ",p->no,p->name,p->marks);
    p=p->next;
    }
    printf("NULL\n");
}
int main(){
    s* start=create();
    printf("\nOriginal List:\n");
    display(start);

    start=insertLast(start);

    printf("\nAfter Inserting at Last:\n");
    display(start);
}