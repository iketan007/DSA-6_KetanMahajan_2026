#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node* create_list() {
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 0;
    head->next = head;
    head->prev = head;
    return head;
}
void insert_start(struct node *list, int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *first = list->next;
    newnode->next = first;
    newnode->prev = list;
    list->next = newnode;
    first->prev = newnode;
}
void insert_end(struct node *list, int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *last = list->prev;
    newnode->next = list;
    newnode->prev = last;
    last->next = newnode;
    list->prev = newnode;
}
void forward_display(struct node *list) {
    struct node *temp = list->next;

    printf("[START] ");
    while(temp != list) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("[END]\n");
}
void reverse_display(struct node *list) {
    struct node *temp = list->prev;

    printf("[END] ");
    while(temp != list) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("[START]\n");
}
struct node* remove_start(struct node *list) {
    if (list->next == list) {
        printf("List is empty\n");
        return list;
    }
    struct node *first = list->next;
    list->next = first->next;
    first->next->prev = list;
    free(first);
    return list;
}
struct node* remove_end(struct node *list) {
    if (list->next == list) {
        printf("List is empty\n");
        return list;
    }
    struct node *last = list->prev;
    struct node *second_last = last->prev;
    second_last->next = list;
    list->prev = second_last;
    free(last);
    return list;
}
int search(struct node *list, int key) {
    struct node *temp = list->next;
    int pos = 1;
    if (list->next == list) {
        printf("List is empty\n");
        return -1;
    }
    while (temp != list) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
    return -1;
}
struct node* destroy(struct node *list) {
    struct node *temp = list->next;
    struct node *nextnode;

    if (list->next == list) {
        printf("List already empty\n");
        return list;
    }
    while (temp != list) {
        nextnode = temp->next;
        free(temp);
        temp = nextnode;
    }
    list->next = list;
    list->prev = list;

    printf("List destroyed successfully\n");
    return list;
}
int main() {
    struct node *list = create_list();

    insert_end(list, 10);
    insert_end(list, 20);
    insert_end(list, 30);

    printf("After insert_end:\n");
    forward_display(list);
    reverse_display(list);

    insert_start(list, 5);

    printf("\nAfter insert_start:\n");
    forward_display(list);
    reverse_display(list);

    printf("\nAfter removing first node:\n");
    list = remove_start(list);
    forward_display(list);

    printf("\nAfter removing last node:\n");
    list = remove_end(list);
    forward_display(list);

    return 0;
}