/*
Singly Linked List
steps:
1)create list+show list
2)insert start
3)insert end 
4)insert after + insert before
5)get start/get end + pop_start/pop_end
6)remove_start/remove_end/remove_data+find+length
7)destroy_list(cleanup)
*/
/*==========================step 1:create_list+show_list===========================*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
/*Create an empty list with a head (dummy)*/
struct node* create_list(void){
    struct node* head = malloc(sizeof(struct node));
    if(!head){
        puts("out of mmory!");
        exit(EXIT_FAILURE);
    }
    head->data=0;
    head->next=NULL;
    return head;
}
void show_list(struct node* head, const char* msg){
    if(msg){
        puts(msg);
        printf("[START]-->");
        struct node* it=head->next;  //it-->iteration
        while(it){
            printf("[%d]->",it->data);
            it=it->next;
        }
        printf("[END]\n");
    
    }
}
/*============================step 2:INSERT START=================*/
void Insert_start(struct node* head,int data)
{
    //step1:Memory Allocation.
    struct node* n=malloc(sizeof(struct node));

    //step2:Allocation check
    if(!n){                      //True If n is Equal to NULl
        puts("out of memory!");
        exit(EXIT_FAILURE);
    }
    n->data=data;
    n->next=head->next;
    head->next=n;
}
/*============================step 3: INSERT END=====================*/
void Insert_end(struct node *head,int data){
    struct node* n=malloc(sizeof(struct node));
    if(!n){
        puts("out of memory!");
        exit(EXIT_FAILURE);
    }
    n->data=data;
    n->next=NULL;
    struct node* it=head;
    while(it->next){
        it=it->next;
    }
    it->next=n;
}
/*=========================step 4:Insert After And Insert Before====================*/
int Insert_After(struct node *head,int After,int data){
    struct node* it=head->next;
    while(it){
        if(it->data==After){
            struct node* n=malloc(sizeof(struct node));
            if(!n){
                puts("out of memory!!");
                exit(EXIT_FAILURE);
            }
            n->data=data;
            n->next=it->next;
            it->next=n;
            return 1;
        }it=it->next;
    }
    return 0;
}
int Insert_Before(struct node *head,int Before,int data){
    struct node *it=head;
    while(it->next){
        if(it->next->data==Before){
            struct node *n=malloc(sizeof(struct node));
            if(!n){
                puts("out of memory!!!!");
                exit(EXIT_FAILURE);
            }
            n->data=data;
            n->next=it->next;
            it->next=n;
            return 1;
        }
        it=it->next;
    }
    return 0;
}
/*step 5: get_start + g_end + pop_start+pop_end*/
int get_start(struct node *head,int *out){
    if(!head->next){
        return 0;
    }
    *out=head->next->data;
    return 1;
}
int get_end(struct node *head,int *out){
    if(!head->next){
        return 0;
    }
    struct node *it=head->next;
    while(it->next){
        it=it->next;
    }
    *out=it->data;
    return 1;
}
int pop_start(struct node *head,int *out){
    if(!head->next){
        return 0;
    }
    struct node *t=head->next;
    *out=t->data;
    head->next=t->next;
    free(t);
    t=NULL;
    return 1;
}
int pop_end(struct node *head,int *out){
    if(!head->next){
        return 0;
    }
    struct node*it=head;
    while(it->next && it->next->next){
        it=it->next;
    }
    struct node *t=it->next;
    *out=t->data;
    it->next=NULL;
    free(t);
    return 1;
}
/*=========================step 6: remove_start(),remove_end(),remove_data()============================*/
int remove_start(struct node *head){
    if(!head->next){
        return 0;
    }
    struct node *t=head->next;
    head->next=t->next;
    free(t);
    t=NULL;
    return 1;
}
int remove_end(struct node *head){
    if(!head->next){
        return 0;
    }
    struct node *it=head;
    while(it->next && it->next->next){
        it=it->next;
    }
    struct node *t=it->next;
    it->next=NULL;
    free(t);
    return 1;
}
int remove_data(struct node* head,int data){
    struct node *it=head;
    while(it->next){
        if(it->next->data=data){
            struct node *t=it->next;
            it->next=t->next;
            free(t);
            t=NULL;
            return 1;
        }
        it=it->next;
    }
    return 0;
}
/*=======================step 7: find + length=================================*/
int find(struct node *head,int data){
    struct node *it=head->next;
    while(it){
        if(it->data==data){
            return 1;
        }
        it=it->next;
    }
    return 0;
}
int length(struct node *head){
    int count=0;
    struct node *it=head->next;
    while(it){
        count++;
        it=it->next;
    }
    return count;
}
/*==============================destroy list====================================*/
void destroy_list(struct node *head){
    struct node *it=head->next;
    while(it){
        struct node* t=it;
        it=it->next;
        free(t);
    }
    head->next=NULL;
    return;
}
int main(void){
    struct node* list=create_list();
    puts("step1:create_list And show_list");
    show_list(list,"list right after creation:");

    Insert_start(list,10);
    Insert_start(list,20);
    Insert_start(list,30);
    show_list(list,"\nAfter Insert_start operation:");

    Insert_end(list,5);
    Insert_end(list,15);
    Insert_end(list,25);
    show_list(list,"\nAfter Insert_end operation:");

    Insert_After(list,10,15);
    Insert_Before(list,5,1);
    show_list(list,"\nAfter Insertion:");

    int x;
    get_start(list,&x);
    printf("\nFirst Element:%d",x);

    get_end(list,&x);
    printf("\nLast Element:%d",x);

    pop_start(list,&x);
    printf("\npop from start:%d",x);

    pop_end(list,&x);
    printf("\npop from end:%d",x);
    show_list(list,"\nAfter poping:");

    remove_start(list);
    remove_end(list);
    remove_data(list,10);
    show_list(list,"\nAfter removal function:");

    printf("find 15 ? %s\n",find(list,15)?"YES":"NO");
    printf("length=%d\n",length(list));

    destroy_list(list);
    show_list(list,"\nAfter destroy list:");

    return 0;
}


