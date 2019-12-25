//
//  adds.c
//  Created by Brandon Molyneaux on 12/24/19.
//

#include "adds.h"

// return 1 if it is unsuccessful
// return 0 if it is successful

// add in an element in an unordered fashion.
u_int add_element_unordered(int element, int_linked_list * list) {
    // initialize a new node and a "search ptr"
    int_list_element * node = init_new_node(element);
    int_list_element * current = init_search_ptr(list);
    
    // if the list size is 0, then front pointer points to node to "create" the list.
    if (list -> size == 0) {
        list -> front = node;
        list -> rear = node;
    }
    else {
        
        // check to see if duplicates are allowed.
        if (list -> allow_dups == false) {
            if (list -> rear -> ele == element) {
                return 0;
            }
        }
        
        list -> rear -> next = node;
        list -> rear = node;
    }
    
    return 0;
}

u_int add_element_ordered_dec(int element, int_linked_list * list) {
    int_list_element * node = init_new_node(element);
    int_list_element * current = init_search_ptr(list);
    
    // Check to see if the list size is 0.
    if (list -> size == 0) {
        list -> front = node;
        list -> rear = node;
        return 0;
    }
    
    // == Inserting into front ==
    
    if (list -> front -> ele <= element) {
        
        // check to see if duplicates are allowed. If not, then check to see
        //  if the element is the same. If so, return it.
        if (list -> allow_dups == false) {
            if (list -> front -> ele == element) {
                return 1;
            }
        }
        
        // insert into front and update front pointer.
        node -> next = list -> front;
        list -> front = node;
        return 0;
    }
    
    // Check to see if new node belongs to the end.
    // comparison: list -> rear -> ele <= element;
    if (list -> rear -> ele >= element) {
        
        // check to see if duplicates are allowed. If not, then check to see
        //  if the element is the same. If so, return it.
        if (list -> allow_dups == false) {
            if (list -> rear -> ele == element) {
                return 1;
            }
        }
        
        // insert into rear and update rear pointer.
        list -> rear -> next = node;
        list -> rear = node;
        return 0;
    }
    
    // check the middle of the list.
    while (current -> next != NULL) {

        // comparison: current -> next -> ele >= element
        if (current -> next -> ele <= element) {
            
            // check to see if duplicates are allowed. If not, then check to see
            //  if the element is the same. If so, return it.
            if (list -> allow_dups == false) {
                if (current -> ele == element) {
                    return 1;
                }
            }
            
            // update the pointers and insert it into the list
            node -> next = current -> next;
            current -> next = node;
            break;
        }
        // move the pointer to the next node.
        current = current -> next;
    }
    return 0;
}

// adds in an element to ensure there's order.
u_int add_element_ordered(int element, int_linked_list * list) {
    int_list_element * node = init_new_node(element);
    int_list_element * current = init_search_ptr(list);
    
    // Check to see if the list size is 0.
    if (list -> size == 0) {
        list -> front = node;
        list -> rear = node;
        return 0;
    }
    
    // == Inserting into front ==
    
    if (list -> front -> ele >= element) {
        
        // check to see if duplicates are allowed. If not, then check to see
        //  if the element is the same. If so, return it.
        if (list -> allow_dups == false) {
            if (list -> front -> ele == element) {
                return 1;
            }
        }
        
        // insert into front and update front pointer.
        node -> next = list -> front;
        list -> front = node;
        return 0;
    }
    
    // Check to see if new node belongs to the end.
    // comparison: list -> rear -> ele <= element;
    if (list -> rear -> ele <= element) {
        
        // check to see if duplicates are allowed. If not, then check to see
        //  if the element is the same. If so, return it.
        if (list -> allow_dups == false) {
            if (list -> rear -> ele == element) {
                return 1;
            }
        }
        
        // insert into rear and update rear pointer.
        list -> rear -> next = node;
        list -> rear = node;
        return 0;
    }
    
    // check the middle of the list.
    while (current -> next != NULL) {

        // comparison: current -> next -> ele >= element
        if (current -> next -> ele >= element) {
            
            // check to see if duplicates are allowed. If not, then check to see
            //  if the element is the same. If so, return it.
            if (list -> allow_dups == false) {
                if (current -> ele == element) {
                    return 1;
                }
            }
            
            // update the pointers and insert it into the list
            node -> next = current -> next;
            current -> next = node;
            break;
        }
        // move the pointer to the next node.
        current = current -> next;
    }
    return 0;
}

// Add in an element to the linked list.
u_int add_element(int element, int_linked_list * list) {
    
    u_int ret_val;
    
    if (list -> ordered == true) {
        if (list -> ascending == true) {
            ret_val = add_element_ordered(element, list);
        }
        else {
            ret_val = add_element_ordered_dec(element, list);
        }
    }
    else {
        ret_val = add_element_unordered(element, list);
    }
    
    if (ret_val == 0) {
        list -> size += 1;
        list -> sum += element;
        list -> average = list -> sum / list -> size;
    }
    
    return 0;
    
}
