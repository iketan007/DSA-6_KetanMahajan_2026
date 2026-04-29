#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int no;
    char name[10];
    int marks;
    struct student* next;
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

    if(head == NULL)
        head = p;
    else
        last->next = p;

    last = p;
    }
    return head;
}
void search(s* head, int key){
    s* temp = head;
    while(temp != NULL){
    if(temp->no == key){
    printf("\n|_%d_|_%s_|_%d_|\n", temp->no, temp->name, temp->marks);
    return;
    }
    temp = temp->next;
    }

    printf("\nNode not found\n");
}
int main(){
    s* start = NULL;
    int key;
    start = create(start);

    printf("Enter Key: ");
    scanf("%d", &key);

    search(start, key);

    return 0;
}