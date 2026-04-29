#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Symbolic constant
#define SUCCESS              1
#define TRUE                 1
#define FALSE                0
#define LIST_DATA_NOT_FOUND  2
#define LIST_EMPTY           3

//node layout definition
struct node
{
    int data;
    struct node* nxt;
};

//interface function declaration
//list creation function
struct node* create_list(void);

//data addition function
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

//get function
int get_start(struct node* p_list, int *p_start_data);
int get_end(struct node* p_list, int *p_end_data);

//pop function
int pop_start(struct node* p_list, int *p_start_data);
int pop_end(struct node* p_list, int *p_end_data);

//remove function
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

//miscellaneous function
int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);
void show_list(struct node* p_list, const char* msg);

//list destruction function
int destory_list(struct node* p_list);


/*
client of Linked List
Entry point Function
*/
int main(void)
{
    struct node* p_list = NULL;
    int status;
    int data, start_data, end_data;
    int length;
    static const char* line = "\n**********************************************************************\n";

    p_list = create_list();
    assert(p_list != NULL);
    printf("List Created Successfully\n");
    puts(line);

    printf("Testing Assertion on the Empty list\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are successful\n");
    puts(line);

    show_list(p_list, "Showing empty list immediately after creation:");
    puts(line);

    for(data=0; data<5; ++data)
    {
        status = insert_start(p_list, data*10);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the start of the list\n", data*10);
    }
    show_list(p_list, "Showing list after inserting 5 data elements at the start:");
    puts(line);

    for(data=1; data<5; ++data)
    {
        status = insert_end(p_list, data*5);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the end of the list\n", data*5);
    }
    show_list(p_list, "Showing list after inserting 5 data elements at the end:");
    puts(line);

    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non-existing data -5\n");
    puts(line);

    status = insert_after(p_list, 0, 100);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting 100 after 0:");
    puts(line);

    status = insert_before(p_list, 43, 200);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 200 after non-existing data 43\n");
    puts(line);

    status = insert_before(p_list, 0, 200);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list before successfully inserting 200 after 0:");
    puts(line);

    status = get_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the Start : %d\n",start_data);
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it: ");
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end : %d\n",end_data);
    show_list(p_list, "Showing list to demonstrate that get_end() returns end data without removing it: ");
    puts(line);

    status = pop_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the Start : %d\n",start_data);
    show_list(p_list, "Showing list to demonstrate that pop_start() remove and return the start data: ");
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end : %d\n",end_data);
    show_list(p_list, "Showing list to demonstrate that get_end() remove and return the end data: ");
    puts(line);

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_start():");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_end():");
    puts(line);

    status = remove_data(p_list, 78);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected error in removing non-existing data 78\n");
    puts(line);

    status = remove_data(p_list, 0);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after removing existing data 0:");
    puts(line);

    status = find(p_list, 91);
    assert(status == FALSE);
    printf("Expected return value FALSE from find() for non-existing data 91\n");
    puts(line);

    status = find(p_list, 100);
    assert(status == TRUE);
    printf("Expected return value TRUE from find() for existing data 100\n");
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Expected return FALSE from is_list_empty()\n");
    puts(line);

    length = get_list_length(p_list);
    printf("Length of the list = %d\n", length);
    puts(line);

    status = destory_list(p_list);
    assert(status == SUCCESS);
    p_list = NULL;
    printf("List is destroyed successfully\n");
    puts(line);

    return 0;
}


/*
Server Side of Linked List
Interface Function Definition
*/
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