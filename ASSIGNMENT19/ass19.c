#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} n;
n* create(n *head) {
    int i, size;
    n *p, *last = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &size);

    for(i = 0; i < size; i++) {
        p = (n*)malloc(sizeof(n));
        printf("Enter data: ");
        scanf("%d", &p->data);
        p->next = NULL;

        if(head == NULL) {
            head = last = p;
        } else {
            last->next = p;
            last = p;
        }
    }
    return head;
}
n* insert(n *head) {
    n *p = (n*)malloc(sizeof(n));

    printf("Enter value to insert: ");
    scanf("%d", &p->data);

    p->next = head;
    return p;
}
n* del(n *head) {
    int key;
    n *temp = head, *prev = NULL;

    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    printf("Enter value to delete: ");
    scanf("%d", &key);

    if(head->data == key) {
        head = head->next;
        free(temp);
        return head;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Value not found\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
    return head;
}
n* reverse(n *head) {
    n *prev = NULL, *curr = head, *next;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void print(n *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    n *head = NULL;
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Create\n2. Insert\n3. Delete\n4. Reverse\n5. Print\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

    switch(choice) {
        case 1: head = create(head); break;
        case 2: head = insert(head); break;
        case 3: head = del(head); break;
        case 4: head = reverse(head); break;
        case 5: print(head); break;
        default: printf("Invalid choice\n");
        }
    } while(choice != 5);
    return 0;
}