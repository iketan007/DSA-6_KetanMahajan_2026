#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
    struct node* reverse;
}node;
node* create(){

    return NULL;
}

void display(node* head){
    node*p=head;
    printf("\n============display linked list===========\n");
    printf("linked list :");
    for(node* p = head;  p != NULL; p = p->next){

        printf(" %d",p->data);
    }        
}

void reverse_display(node* head){
    node*p=head;
    for(node* p = head;  p != NULL; p = p->next){
 printf("\n==================display reverse linked list=============================\n");
 printf("linked list:");
    for(node* p = head;  p != NULL; p = p->prev){
        printf("%d",p->data);
    }
 }
}

node* insert_start(node* head,int data){

    node* new = (node*)malloc(sizeof(node));

    new->data = data;
    new->prev = NULL;
    new->next = head;

    if(head != NULL){
        
        head->prev = new;
    
    }
    
    return new;
}

node* insert_end(node* head,int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        return newNode;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
node* delete_start(node* head){

    if(head == NULL){
        printf("List is empty");
        return NULL;
    }
    node* temp = head;
    head = head->next;

    if(head != NULL){       
        head->prev = NULL;
    }
    free(temp);
    return head;
}
node* delete_end(node* head)
{
   if (head == NULL) {
        printf("List is Empty");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node* temp = head;
   
    while (temp->next != NULL) {

        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}
void search(node* head,int data){

    if (head == NULL) {
        printf("List is Empty");
        
    }
    
    int flag = 0;
    for(node* p = head; p!= NULL; p = p->next){

        if(p->data == data){

            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("found");

    }else{
        printf("not found");
    }
}
node* destroy(node* head){

    node* p = head;
    while(p != NULL){

       node* temp = p->next;
       free(p);
       p = temp; 
    }
    return NULL;
}

int main(){

    node* start = create();

    start = insert_end(start,10);
    start = insert_end(start,20);
    start = insert_end(start,30);
    start = insert_end(start,40);
    start = insert_end(start,50);
    start = insert_end(start,60);
    start = insert_end(start,70);

    display(start);

    //printf("\ndelete last elememt :");
    //start = delete_end(start);
    //display(start);

    //printf("\ndelete start elememt :");
    //start = delete_start(start);
    //display(start);

    //printf("\nsearch for 40 :");
    //search(start, 40);
    //printf("\nsearch for 80 :");
    //search(start, 80);

    //start = destroy(start);
    //display(start);

    start = reverse(start);
    display(start);

    return 0;
}