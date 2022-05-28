#include "lin.h"

list *create(int data)
{

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> value = data;

    tmp -> next = NULL;
    
    return(tmp);

}

list *add_element_start(int data, list *head)
{

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> value = data;

    tmp -> next = head;
    
    return(tmp);
}

void add_element_end(int data, list *head)
{

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> value = data;

    tmp -> next = NULL;
    
    list *p = head;

    while (p -> next != NULL) {
        p = p -> next;
    }

    p -> next = tmp;
}

list *add_element_n_position(int data, int n, list *head)
{
    list *p = head;

    int count = 0;

    while (count < n - 1 && p -> next != NULL) {
        
            p = p -> next;
            count++;
            
        }

    list *tmp = (list*)malloc(sizeof(list));

    tmp -> value = data;

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

        printf("%d ", tmp -> value);

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

void switching(list *p) {
    
    while(p -> next != NULL) {
        
        list *switcher = p -> next;
        
        if (p -> value > switcher -> value) {
            int changer = switcher -> value;
            switcher -> value = p -> value;
            p -> value = changer;
        }
        
        p = p->next;
        
    }
    
}

list *bubble_sort(list *head) {
    
    list *tmp = head;
    
    for(int i = 0; i < list_size(head) - 1; i++) {
        switching(tmp);
    }
    
    return head;
    
} 
