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
n* delete_after(n* h, int key){
    n *q = h;
    while(q){
    if(q->no == key){
    if(q->next == NULL){
    printf("No node after key!\n");
    return h;
    }

    n *temp = q->next;
    q->next = temp->next;
    free(temp);

    return h;
        }
    q = q->next;
        }

    printf("Key not found!\n");
    return h;
    }
int main(){
    n *head=create();
    display(head);
    int key;
    printf("Key: ");
    scanf("%d",&key);

    printf("New node (no name marks): ");
    head=delete_after(head,key);

    display(head);
    return 0;
}