//
//  inits.c
//  
//
//  Created by Brandon Molyneaux on 12/24/19.
//

#include "inits.h"
#include <stdlib.h>

// === Unordered Linked Lists

// Instatiates unordered linked list
int_linked_list * init_unordered_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = false;
    list -> allow_dups = true;
    return list;
}

// Instatiates unordered linked list, no duplicates
int_linked_list * init_unordered_no_duplicates_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = false;
    list -> allow_dups = false;
    return list;
}
// ======

// === Ordered Linked Lists

// Instantiates ordered linked ascending list (allows duplicates)
int_linked_list * init_ordered_asc_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = true;
    list -> ascending = true;
    list -> allow_dups = true;
    return list;
}

// Instantiates ordered linked ascending list (no duplicates)
int_linked_list * init_ordered_asc_no_duplicates_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = true;
    list -> ascending = true;
    list -> allow_dups = false;
    return list;
}

// Instantiates ordered linked descending list (allow duplicates)
int_linked_list * init_ordered_dec_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = true;
    list -> ascending = false;
    list -> allow_dups = true;
    return list;
}

// Instantiates ordered linked descending list (no duplicates)
int_linked_list * init_ordered_dec_no_duplicates_linked_list() {
    int_linked_list * list;
    list = malloc(sizeof(int_linked_list));
    list -> size = 0;
    list -> sum = 0;
    list -> ordered = true;
    list -> ascending = false;
    list -> allow_dups = false;
    return list;
}

// ======

// === Misc. instatiations needed to support linked lists.

// initiates a pointer to iterate through a given list.
int_list_element * init_search_ptr(int_linked_list * list) {
    int_list_element * current;
    current = malloc(sizeof(int_list_element));
    current = list -> front;
    return current;
}

// instatiates a new node to be added into the linked list.
int_list_element * init_new_node(int element) {
    int_list_element * node;
    node = malloc(sizeof(int_list_element));
    node -> ele = element;
    node -> next = NULL;
    return node;
}

// =======
