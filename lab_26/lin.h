#ifndef LIN_H
#define LIN_H

#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    
    int value;
    struct Node *next;
    
} list;
 
list *create(int data);

list *add_element_start(int data, list *head);

void add_element_end(int data, list *head);

list *add_element_n_position(int data, int n, list *head);

list *delete_list(list *head);

list *delete_element(list *head, int position);

void print_list(list *head);

int list_size(list *head);

void switching(list *p);

list *bubble_sort(list *head);

#endif
