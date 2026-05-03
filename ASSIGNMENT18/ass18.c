#include<stdio.h>
#include<stdlib.h>
typedef struct student{
    int no;
    char name[10];
    int marks;
    struct student *next;
} s;
s* create(s* head){
    int n, i;
    s *p, *last = NULL;

    printf("How many records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        p = (s*)malloc(sizeof(s));

    printf("Enter no name marks: ");
    scanf("%d %s %d", &p->no, p->name, &p->marks);

    p->next = NULL;

    if(head == NULL){
        head = p;
        last = p;
        }
    else{
        last->next = p;
        last = p;
        }
    }
    return head;
}
s* reverse(s* head){
    s *prev = NULL, *curr = head, *next;

    while(curr != NULL){
    next = curr->next;  
    curr->next = prev;   
    prev = curr;        
    curr = next;     
    }
    return prev;
}
void display(s* head){
    while(head != NULL){
        printf("|%d %s %d| -> ",head->no,head->name,head->marks);
        head = head->next;
    }
    printf("NULL\n");
}
int main(){
    s* start = NULL;
    start = create(start);
    printf("\nOriginal List:\n");
    display(start);

    start = reverse(start);
    printf("\nReversed List:\n");
    display(start);

    return 0;
}