//
//  removes.c
//  
//
//  Created by Brandon Molyneaux on 12/24/19.
//

#include "removes.h"
#include <stdlib.h>

// return 1 if unsuccessful
// return 0 if successful

// removes the first instance of the element in an unordered list.
u_int remove_node(int element, int_linked_list * list) {
    int_list_element * current = init_search_ptr(list); // create new search pointer
    
    // check to see if the element is bigger than any of the node elements.
    //  If so, then there's no need to search further.
    if (list -> ordered == true) {
        if (list -> rear -> ele < element) {
            return 1;
        }
    }
    
    // check to see if it's the first element.
    if (list -> front -> ele == element) {
        list -> front = list -> front -> next; // move front to next; current is still old front
        free(current);
        return 0;
    }
    
    // check to see if it's the rear element.
    if (list -> rear -> ele == element) {
        while (current -> next -> next != NULL) {
            current = current -> next;
        }
        
        list -> rear = current; // set rear one back
        current = current -> next; // move current to next node
        list -> rear -> next = NULL; // set rear's next to be null
        free(current); // free the current pointer; also frees the node
        return 0;
    }
    
    // if it's in the middle
    int itr = 0;
    while (current -> next -> next != NULL) {
        if (list -> ordered == true) {
            if (current -> next -> ele > element) {
                return 1;
            }
        }
        
        if (current -> next -> ele == element) {
            int_list_element * temp = init_search_ptr(list); // create new search pointer
            temp = current -> next; // temporary pointer to the node to be removed
            current -> next = current -> next -> next; // "hop" pointer over node to be removed
            temp -> next = NULL; // set the node to be removed
            free(temp); // remove it entirely.
            return 0;
        }
        
        current = current -> next;
    }
    
    return 1;
}

// Remove an element from the linked list
u_int remove_element(int element, int_linked_list * list) {
    
    u_int ret_val;
    ret_val = remove_node(element, list);
    
    if (ret_val == 0) {
        list -> size -= 1;
        list -> sum -= element;
        if (list -> size == 0) {
            list -> average = 0;
        }
        else {
            list -> average = list -> sum / list -> size;
        }
    }
    
    return 0;
}

