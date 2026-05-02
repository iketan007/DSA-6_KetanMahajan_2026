#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} n;
n* create(int count){
    n *temp;
    if(count == 0)
        return NULL;
    temp = (n*)malloc(sizeof(n));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    temp->next = create(count - 1); 
    return temp;
}
void display(n *head){
    if(head == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", head->data);
    display(head->next);   
}
int main(){
    n *head = NULL;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = create(n);

    printf("\nLinked List:\n");
    display(head);

    return 0;
}