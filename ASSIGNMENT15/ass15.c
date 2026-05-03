#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void sort(s* head){
    s *i,*j;
    int temp_no,temp_marks;
    char temp_name[10];

    for(i=head;i!=NULL;i=i->next){
    for(j=i->next;j!=NULL;j=j->next){

    if(i->no > j->no){

    temp_no=i->no;
    i->no=j->no;
    j->no=temp_no;

    temp_marks=i->marks;
    i->marks=j->marks;
    j->marks=temp_marks;

    strcpy(temp_name,i->name);
    strcpy(i->name,j->name);
    strcpy(j->name,temp_name);
    }
    }
    }
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

    sort(start);
    printf("\nSorted List:\n");
    display(start);
}