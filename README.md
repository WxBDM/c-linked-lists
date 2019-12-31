# Linked Lists in C  
This repository's goal is to demonstrate a singly-linked list implementation in C. By no means this is the most efficient implementation in terms of readability, but it is a viable method. In addition, it is built to (somewhat) easily integrate into your project - see below for usage, examples, and integration.

The biggest drawback to this mini-project (at the time of writing) is that you are only able to use integers as elements. However, this can easily be fixed if you read through the source code. I will not explain how to do this in this README file.

# Usage  
This mini-project supports various types of singly-linked lists in C, which are shown below:

|     Type of List    | Allow Duplicates? |                  Init function                 |
|:-------------------:|:-----------------:|:----------------------------------------------:|
|      Unordered      |        Yes        |         `init_unordered_linked_list()`         |
|      Unordered      |         No        |  `init_unordered_no_duplicates_linked_list()`  |
|  Ordered, Ascending |        Yes        |        `init_ordered_asc_linked_list()`        |
|  Ordered, Ascending |         No        | `init_ordered_asc_no_duplicates_linked_list()` |
| Ordered, Descending |        Yes        |        `init_ordered_dec_linked_list()`        |
| Ordered, Descending |         No        | `init_ordered_dec_no_duplicates_linked_list()` |

In order to begin adding to a linked list, you must first instatiate a linked list by referring to the table above. Once it is instatiated, then you can begin adding and removing elements. See examples below.

# Examples
The main function (found in `main.c`) contains driver code to demonstrate how to add (and soon remove) elements from a linked list. You may use this for reference.

Example 1) Adding 3 elements into an unordered linked list (that allows duplicates) and removing an element
```c
int main() {
    int_linked_list * list = init_unordered_linked_list(); // instantiate
    add_element(6, list); // add 6 into the list
    add_element(2, list); // add 2 into the list
    add_element(5, list); // add 5 into the list
    add_element(12, list); // adds 12 into the list
    remove_element(2, list); // removes first instance of element 2
    return 0;
}
```
When printed using `print_elements()` (built into `main.c`), you will see:
```c
6
5
12
```

Example 2) Adding 5 elements into an ordered ascending linked list that allows duplicates:
```c
int main() {
    int_linked_list * list = init_unordered_linked_list(); // instantiate list
    add_element(6, list); // add 6 into the list
    add_element(2, list); // add 2 into the list
    add_element(-1, list); // add -1 into the list
    add_element(-3, list); // add -3 into the list
    add_element(8, list); // add 8 into the list
    return 0;
}
```
When printed using `print_elements()` (built into `main.c`), you will see:
```c
-3
-1
2
6
8
```
Example 3) Adding in 5 elements into a descending-ordered linked list with no duplicates.
```c
int main() {
    int_linked_list * list = init_ordered_dec_no_duplicates_linked_list();
    add_element(6, list);
    add_element(2, list);
    add_element(2, list);
    add_element(-3, list);
    add_element(8, list);
    return 0;
}
```
When printed using `print_elements()`:
```c
8
6
2
-3
```

# Integrating into your project
I built this so that it could be (somewhat) easily integrated into your project. Note that the biggest takeaway from this is that you can only use integers as elements. If you know how to modify it such that you are able to use other data types, feel free to do so at your convinience. It is recommended to create a Makefile if you do not have one.

__If you use this for your project, please give proper credit by linking this GitHub repository inside of the project and project documentation.__

Fork and clone the repository onto your machine. 
1. Move the following c and header files into your project directory: `adds`, `inits`, `removes`
2. Type the following into the `.c` file where you plan on using linked lists:
```c
#include "adds.h"
#include "inits.h"
#include "removes.h"
```
3. If you have a Makefile, be sure to update it to include these files.

Note that you do NOT have to move `main.c` or `main.h`, as this is the driver file for the code.
