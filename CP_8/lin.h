#ifndef LIN_H
#define LIN_H

#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct Node {
    
    char value[30];
    struct Node *next;
    
} list;
 
list *create(char data[30]);

list *add_element_start(char data[30], list *head);

void add_element_end(char data[30], list *head);

list *add_element_n_position(char data[30], int n, list *head);

list *delete_list(list *head);

list *delete_element(list *head, int position);

void print_list(list *head);

int list_size(list *head);

list *mid_delete(int n, list *head);

#endif
