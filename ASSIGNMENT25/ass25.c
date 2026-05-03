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
int count(n* h){
    int c = 0;
    while(h){
        c++;
        h = h->next;
    }
    return c;
}
int main(){
    n *head = create();
    display(head);
    int size = count(head);
    printf("Size of list = %d\n", size);

    return 0;
}