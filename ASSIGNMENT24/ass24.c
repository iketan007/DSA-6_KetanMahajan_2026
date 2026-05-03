#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int no, marks;
    char name[10];
    struct node *next;
}n;
n* create(){
    int i, size;
    n *head=NULL,*last=NULL,*p;

    printf("Nodes: ");
    scanf("%d",&size);

    for(i=0;i<size;i++){
    p=(n*)malloc(sizeof(n));
    scanf("%d %s %d",&p->no,p->name,&p->marks);
    p->next=NULL;

    if(!head) head=last=p;
    else{
        last->next=p;
        last=p;
        }
    }
    return head;
    }
void display(n* q){
    while(q){
    printf("|_%d_|_%s_|_%d_| -> ",q->no,q->name,q->marks);
    q=q->next;
    }
    printf("NULL\n");
    }
n* delete_before(n* h,int key){
n *prev=NULL,*curr=h;
    if(!h || !h->next){
    printf("Deletion not possible\n");
    return h;
    }
if(h->next->no==key){
    n *temp=h;
    h=h->next;
    free(temp);
    return h;
    }
while(curr->next && curr->next->no!=key){
    prev=curr;
    curr=curr->next;
    }
if(curr->next==NULL){
    printf("Key not found\n");
    return h;
    }
    prev->next=curr->next;
    free(curr);

    return h;
}
int main(){
    n *head=create();
    display(head);
    int key;
    printf("Key: ");
    scanf("%d",&key);

    printf("New node (no name marks): ");
    head=delete_before(head,key);

    display(head);
    return 0;
}