//
//  main.c
//  Driver code for linked lists.
//
//  Created by Brandon Molyneaux on 12/23/19.
//

#include "main.h"
#include "inits.h"
#include "adds.h"
#include "removes.h"

// prints the element of the list.
void print_elements(int_linked_list * list) {
    int_list_element * current = init_search_ptr(list);

    // iterate through the list and print the element
    for (int i = 0; i < list -> size; i++) {
        printf("Element: %d\n", current -> ele);
        current = current -> next;
    }
    
    free(current); // free the pointer
}

/*
 * Driver code for linked list implementation. This is a mere demonstration of how
 *  the code works.
 */
int main() {

    // Example 1
    // create a linked list in ascending order.
    int_linked_list * ordered_asc_list = init_ordered_asc_linked_list();
    
    // add in a bunch of arbitrary values
    add_element(6, ordered_asc_list);
    add_element(2, ordered_asc_list);
    add_element(-3, ordered_asc_list);
    add_element(8, ordered_asc_list);
    add_element(1, ordered_asc_list);
    add_element(2, ordered_asc_list);
    
    // remove some of them and one that isn't in the list.
    remove_element(2, ordered_asc_list);
    remove_element(0, ordered_asc_list);
    
    printf("Example 1 linked list output:\n");
    print_elements(ordered_asc_list);
    
    
    // Example 2
    // Create a linked list with no duplicates in descending order.
    int_linked_list * list = init_ordered_dec_no_duplicates_linked_list();

    // arbitrarily add in a bunch of elements
    add_element(3, list);
    add_element(4, list);
    add_element(5, list);
    add_element(6, list);
    add_element(1, list);
    add_element(1, list);
    add_element(1, list);
    add_element(53, list);
    add_element(64, list);
    add_element(28, list);
    add_element(18, list);
    add_element(-5, list);
    add_element(-84, list);
    add_element(63, list);
    add_element(98, list);
    add_element(92, list);
    add_element(-12, list);
    add_element(-1, list);
    
    // now remove some numbers.
    remove_element(5, list);
    remove_element(1, list);
    remove_element(1, list);
    remove_element(-12, list);

    printf("\nExample 2 linked list output:\n");
    print_elements(list);
    return 0;
}
