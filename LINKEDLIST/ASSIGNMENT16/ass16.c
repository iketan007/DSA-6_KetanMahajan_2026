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
void reverseDisplay(s* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    s *end = NULL;
    while(1){
        s *p = head;
    while(p->next != end){
        p = p->next;
        }
    printf("%d %s\n", p->no, p->name);

    if(p == head)  
        break;

    end = p;
    }
}
int main(){
    s* start = NULL;
    start = create(start);

    printf("\nReverse Display:\n");
    reverseDisplay(start);

    return 0;
}