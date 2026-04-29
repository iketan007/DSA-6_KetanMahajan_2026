#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} node;
void find_middle(node* head){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    node *slow=head,*fast=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("Middle node data = %d\n", slow->data);
}
int main(){
    int n;
    printf("How many nodes: ");
    scanf("%d",&n);
    node *head=NULL,*last=NULL,*p;
    while(n--){
        p=(node*)malloc(sizeof(node));
        printf("Enter data: ");
        scanf("%d",&p->data);
        p->next=NULL;

        if(!head) head=p;
        else last->next=p;

        last=p;
    }
    find_middle(head);
    return 0;
}