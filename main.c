//
//  main.c
//  Driver code for linked lists.
//
//  Created by Brandon Molyneaux on 12/23/19.
//

#include "main.h"
#include "inits.h"
#include "adds.h"

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

int main() {
    
    int_linked_list * list = init_ordered_dec_no_duplicates_linked_list();
    
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

    print_elements(list);

    printf("Size of list: %d\n", list -> size);
    printf("Sum of list: %d\n", list -> sum);
    printf("Avg of the list: %d\n", list -> average);

    return 0;
}
