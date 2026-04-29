//header file
#ifndef LIST_H
#define LIST_H


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

#endif
