#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;

void merge(node*head1,node*head2){
if(head1==NULL && head2==NULL){
    printf("empty list");
}
node*p=head1;
node*q=head2;
}