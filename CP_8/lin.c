#include "lin.h"

list *create(char data[30])
{

    list *tmp = (list*)malloc(sizeof(list));

    strcpy(tmp -> value, data);

    tmp -> next = NULL;
    
    return(tmp);

}

list *add_element_start(char data[30], list *head)
{

    list *tmp = (list*)malloc(sizeof(list));

    strcpy(tmp -> value, data);

    tmp -> next = head;
    
    return(tmp);
}

void add_element_end(char data[30], list *head)
{

    list *tmp = (list*)malloc(sizeof(list));

    strcpy(tmp -> value, data);

    tmp -> next = NULL;
    
    list *p = head;

    while (p -> next != NULL) {
        p = p -> next;
    }

    p -> next = tmp;
}

list *add_element_n_position(char data[30], int n, list *head)
{
    list *p = head;

    int count = 0;

    while (count < n - 1 && p -> next != NULL) {
        
            p = p -> next;
            count++;
            
        }

    list *tmp = (list*)malloc(sizeof(list));

    strcpy(tmp -> value, data);

    tmp -> next = p -> next;

    p -> next = tmp;
    
    return head;
}

list *delete_list(list *head)
{

    while (head != NULL) {

        list *p = head;
        head = head -> next;
        
        free(p);
    }
    return NULL;
    
}

list *delete_element(list *head, int position) {
    
    if(head == NULL) {
        return NULL;
    }
    
    int element = 0;
    
    list *tmp = head;
    list *p = NULL;
    
    while(element <  position) {
        
        p = tmp;
        tmp = tmp -> next;
        element++;
        
    }
    
    if (tmp == head) {
        return tmp -> next;
        free(head);
    }
    
    p -> next = tmp -> next;
    
    free(tmp);
    
    return head;
    
}

void print_list(list *head) {
    
    list *tmp = head;
    
    while (tmp != NULL) {

        printf("%s ", tmp -> value);

        tmp = tmp -> next;
    }
}

int list_size(list *head) {
    
    int size = 0;
    
    list *tmp = head;
    
    while (tmp != NULL) {

        size++;

        tmp = tmp -> next;
    }
    
    return size;
    
}

list *mid_delete(int n, list *head) {
    
    if(list_size(head) - n <= 0) {
        
        printf("Sorry, we can't delete this amount of elements\n\n");
        return head;
        
    }
    
    int position_to_delete = (list_size(head) - n) / 2;
    
    for(int i = 0; i < n; i++) {
        
        delete_element(head, position_to_delete);
        
    }
    
    return head;
}
