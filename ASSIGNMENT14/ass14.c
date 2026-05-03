#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int no, marks;
    char name[10];
    struct node* next;
} node;
void find_middle(node* head){
    if(head == NULL){
    printf("List is empty\n");
    return;
    }
    node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    }
    printf("Middle node = |%d %s %d|\n", slow->no, slow->name, slow->marks);
}
void display(node* p){
    while(p){
    printf("|%d %s %d| -> ", p->no, p->name, p->marks);
    p = p->next;
    }
    printf("NULL\n");
}
int main(){
    int n;
    printf("How many nodes: ");
    scanf("%d",&n);
    node *head=NULL,*last=NULL,*p;
    while(n--){
    p = (node*)malloc(sizeof(node));
    printf("Enter no name marks: ");
    scanf("%d %s %d",&p->no,p->name,&p->marks);
    p->next = NULL;

    if(head == NULL)
        head = p;
    else
        last->next = p;

    last = p;
    }
    printf("\nLinked List:\n");
    display(head);

    find_middle(head);
    return 0;
}