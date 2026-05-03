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
s* deleteByKey(s* head){
    int key;
    printf("Enter key (no): ");
    scanf("%d",&key);
    if(!head){
    printf("List is empty\n");
    return NULL;
    }
    if(head->no == key){
        s* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    s *p = head;
    while(p->next && p->next->no != key)
    p = p->next;

    if(!p->next){
    printf("Node not found\n");
    return head;
    }
    s* temp = p->next;
    p->next = temp->next;
    free(temp);
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
    s* start = create();
    printf("\nOriginal List:\n");
    display(start);

    start = deleteByKey(start);
    printf("\nAfter Deletion:\n");
    display(start);
}