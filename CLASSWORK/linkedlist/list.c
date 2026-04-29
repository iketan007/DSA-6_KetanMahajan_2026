/*
Server Side of Linked List
Interface Function Definition
*/
#include<stdio.h>
#include<stdlib.h>
#include"list.h"
struct node* create_list()
{
    struct node* head_node = NULL;
    head_node = (struct node*)malloc(sizeof(struct node*));

    if(head_node == NULL)
    {
        printf("Memory not allocated\n");
        exit (EXIT_FAILURE);
    }

    head_node->data = 0;
    head_node->nxt = NULL;
    return head_node;
};  

//Insert Start function;
int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node*));

    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
        exit (EXIT_FAILURE);
    }

    new_node->data = new_data;

    new_node->nxt = p_list->nxt;
    p_list->nxt = new_node;
    return SUCCESS;
}

//Insert End Function
int insert_end(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    struct node* run = NULL;
    new_node = (struct node*)malloc(sizeof(struct node*));

    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
        exit (EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->nxt = NULL;

    run = p_list;

    while(run->nxt != NULL){
        run = run->nxt;
    }

    run->nxt = new_node;
    return SUCCESS;
}

//Insert After existing data
int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    run = p_list->nxt;

    while(run != NULL)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run = run->nxt;
    }

    if(run == NULL)
    {
        return LIST_DATA_NOT_FOUND;
    }

    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node*));
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
        exit (EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->nxt = existing_node->nxt;
    existing_node->nxt = new_node;

    return SUCCESS;
}

//insert before existing data
int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* run_prev = NULL;
    struct node* new_node = NULL;

    //search for the 1st occurance of the existing data with maintaining the back pointer
    run_prev = p_list;
    run = p_list->nxt;

    while(run != NULL)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run_prev = run;
        run = run->nxt;
    }

    //if the existing data is not found then return error message 
    if(run == NULL)
    {
        return LIST_DATA_NOT_FOUND;
    }

    //allocate and initialize memory
    new_node = (struct node*)malloc(sizeof(struct node*));
    if(new_node == NULL)
    {
        printf("Memory not allocated\n");
        exit (EXIT_FAILURE);
    }
    new_node->data = new_data;
    new_node->nxt = run;
    run_prev->nxt = new_node;

    return SUCCESS;
}

//Get start data
int get_start(struct node* p_list, int *p_start_data)
{
    if(p_list->nxt != NULL)
    {
        *p_start_data = p_list->nxt->data;
        return SUCCESS;
    }
    return LIST_EMPTY;
}

//Get end data
int get_end(struct node* p_list, int *p_end_data)
{
    if(p_list->nxt == NULL)
        return LIST_EMPTY;
    
    struct node* run = NULL;
    run = p_list->nxt;
    while (run->nxt != NULL)
    {
        run = run->nxt;
    }
    *p_end_data = run->data;
    return SUCCESS;
}

//Pop function
int pop_start(struct node* p_list, int *p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;
    struct node* delete_nxt = NULL;

    if(p_list->nxt == NULL)
        return LIST_EMPTY;
    
    *p_start_data = p_list->nxt->data;
    delete_prev = p_list;
    delete_node = p_list->nxt;
    delete_nxt = delete_node->nxt;

    delete_prev->nxt = delete_nxt;
    free(delete_node);
    delete_node = NULL;
    return SUCCESS;
}

int pop_end(struct node* p_list, int *p_end_data)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;

    if(p_list->nxt == NULL)
        return LIST_EMPTY;
    
    delete_prev = p_list;
    delete_node = p_list->nxt;

    while (delete_node->nxt != NULL)
    {
        delete_prev = delete_node;
        delete_node = delete_node->nxt;
    }
    *p_end_data = delete_node->data;

    free(delete_node);
    delete_prev->nxt = NULL;
    delete_node = NULL;
    return SUCCESS;
}

//Remove Function
int remove_start(struct node* p_list)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;
    struct node* delete_nxt = NULL;

    if(p_list->nxt == NULL)
        return LIST_EMPTY;
    
    delete_prev = p_list;
    delete_node = p_list->nxt;
    delete_nxt = delete_node->nxt;

    delete_prev->nxt = delete_nxt;
    free(delete_node);
    delete_node = NULL;
    return SUCCESS;
}

int remove_end(struct node* p_list)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;

    if(p_list->nxt == NULL)
        return LIST_EMPTY;
    
    delete_prev = p_list;
    delete_node = p_list->nxt;

    while (delete_node->nxt != NULL)
    {
        delete_prev = delete_node;
        delete_node = delete_node->nxt;
    }

    free(delete_node);
    delete_prev->nxt = NULL;
    delete_node = NULL;
    return SUCCESS;
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* delete_node = NULL;
    struct node* delete_prev = NULL;

    if(p_list->nxt == NULL)
        return LIST_EMPTY;

    delete_prev = p_list;
    delete_node = p_list->nxt;

    while (delete_node != NULL)
    {   
        if(delete_node->data == r_data)
            break;

        delete_prev = delete_node;
        delete_node = delete_node->nxt;
    }

    if(delete_node == NULL)
    {
        return LIST_DATA_NOT_FOUND;
    }

    delete_prev->nxt = delete_node->nxt;
    free(delete_node);
    delete_node = NULL;
    return SUCCESS;
}

//miscellaneous function
int find(struct node* p_list, int f_data)
{
    struct node* run = NULL;

    run = p_list->nxt;
    while(run->nxt != NULL)
    {
        if(run->data == f_data)
        {
            return TRUE;
        }
        run = run->nxt;
    }
    return FALSE;
}

int get_list_length(struct node* p_list)
{
    int length = 0;
    struct node* run = NULL;

    run = p_list->nxt;
    while(run != NULL)
    {
        length = length + 1;
        run = run->nxt;
    }
    return length;
}

int is_list_empty(struct node* p_list)
{
    if(p_list->nxt == NULL)
    {
        return TRUE;
    }
    return FALSE;
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* run = NULL;
    if(msg != NULL)
    {
        puts(msg);
    }
    printf("[START]->");

    run = p_list->nxt;
    while(run != NULL){
        printf("[%d]->",run->data);
        run = run->nxt;
    }
    printf("[END]\n");
}


//List destruction function
int destory_list(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_nxt = NULL;

    run = p_list;
    while (run!=NULL)
    {
        run_nxt = run->nxt;
        free(run);
        run = run_nxt;
    }
    return SUCCESS;
}