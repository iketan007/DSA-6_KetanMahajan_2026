/*
client of Linked List
Entry point Function
*/
#include<stdio.h>
#include<assert.h>
#include"list.h"
int main(void)
{
    struct node* p_list = NULL;
    int status;
    int data, start_data, end_data;
    int length;
    static const char* line = "**********************************************************************";

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