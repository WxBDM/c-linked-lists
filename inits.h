//
//  inits.h
//  
//
//  Created by Brandon Molyneaux on 12/24/19.
//

#ifndef inits_h
#define inits_h

#include <stdio.h>

typedef unsigned int u_int;
typedef enum {false, true} bool;

// individual nodes containing value and pointer to next node.
typedef struct node {
    int ele;
    struct node * next; // pointer to next node
} int_list_element;

// the structure to "hold" all of the different nodes.
typedef struct {
    int_list_element * front;
    int_list_element * rear;
    u_int size;
    u_int sum;
    u_int average;
    bool ordered;
    bool ascending;
    bool allow_dups;
} int_linked_list;

// Unordered linked lists
int_linked_list * init_unordered_linked_list();                 // works
int_linked_list * init_unordered_no_duplicates_linked_list();   // works

// Ordered linked lists
int_linked_list * init_ordered_asc_linked_list();               // works
int_linked_list * init_ordered_asc_no_duplicates_linked_list(); // works
int_linked_list * init_ordered_dec_linked_list();               // works
int_linked_list * init_ordered_dec_no_duplicates_linked_list(); // haven't tested

// Misc. instatiations
int_list_element * init_search_ptr(int_linked_list * list);
int_list_element * init_new_node(int element);

#endif /* inits_h */
