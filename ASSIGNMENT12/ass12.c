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
s* deleteLast(s* head){
    if(!head){
    printf("List is empty\n");
    return NULL;
    }
    if(!head->next){
    free(head);
    return NULL;
    }
    s *p=head;
    while(p->next->next)
    p=p->next;
    free(p->next);     
    p->next=NULL;      

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

    start=deleteLast(start);

    printf("\nAfter Deleting Last Node:\n");
    display(start);
}