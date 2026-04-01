#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct s{
    int no;
    char name[10];
    struct s *next;
} s;
s *create(s *head){
    s *last = NULL;
    int choice;
     do {
        s *p = (s*) malloc(sizeof(s));
        printf("\nEnter no and name: ");
        scanf("%d %s", &p->no, p->name);
        p->next = NULL;
        if (head == NULL){
            head = p;
        }
        else{
            last->next = p;
        }
         last = p;
        printf("Do you want to enter more records? (1/0): ");
        scanf("%d", &choice);
    } while (choice == 1);
     return head;
}
void display(s *p){
    for (; p != NULL; p = p->next)
    {
        printf("%d %s\n", p->no, p->name);
    }
}
void alternatedisp(s *temp){
   if (temp == NULL){
    printf("list is not created");
    return;
   }
    
    for(;temp!=NULL;temp=temp->next->next)
{
    printf("%d %s\n",temp->no,temp->name);
    if(temp->next==NULL)
    break;
}
}
void swap(s *head){
    if(head == NULL)
    return;
    s *p, *q;
    for(s *p=head;p!=NULL;p=q->next)
    {
        q=p->next;
        if(q==NULL)
        break;
        char tempname[10];
        int temp=p->no;
        p->no=q->no;
        q->no=temp;
        strcpy(tempname,p->name);
        strcpy(p->name,q->name);
        strcpy(q->name,tempname);
     }
    }
void add(s *head){
    if(head==NULL)
    return;
    s *p=head,*q,*new;
    for(;p!=NULL&&p->next!=NULL;p=new->next);
    {
        q=p->next;
        new=(s *)malloc(sizeof(s));
        if(!new){
            ("memory allocation failed\n");
            return;
            new->no=p->no+q->no;
            strcpy(new->name,strcat(p->name,q->name));
            new->next=new;
            q->next=new;
        }
        }
    }
int main(){
    s *start = NULL;
    start = create(start);
    display(start);
    printf("Alternate display");
    alternatedisp(start);
    swap(start);
    printf("swap");
    display(start);
     return 0;
}