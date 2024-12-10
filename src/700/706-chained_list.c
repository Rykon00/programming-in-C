/* Chained list.c

   The (chained) list is a very important concept to manage sets of items dynamically:
   - The maximum number of elements does not need to be known in advance
   - Elements can have different sizes
   - Elements can be added and removed flexibly

   Key concepts of such a list are:
   - Each data item is stored in its own section of memory
   - There is a pointer to the first data item (or NULL, when the list is empty)
   - Each data item has a pointer to the next item in the list (or to NULL, if it's the last item in the list)

   The program below already contains some important definitions and functions.

   TO DO 1: Have a look at the program, get it running and try to understand how it works.
            - Print out pointer values to keep track of what the program does.
                        - At what position is a new item added to the list (beginning or end?)
   TO DO 2: Extend main, such that more items are added to the list
   TO DO 3: Complete the function print_items to print for each item in the list:
                        - the name, the address in memory and the address of its successor
            In addition, calculate the sum of all data payloads.
   TO DO 4: Write a function find_item(...) that searches the list for an item with a given guid.
   TO DO 5: Write a function delete_item(...) to delete an item from the list.
   TO DO 6: Experience 'Memory leaks':
            - Increase the size of the payload.
                        - Change your delete function so that it does not free the memory correctly.
                        - Add and remove items frequently in a big loop.
                        - Use e.g. the task manager to see what happens with memory.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Data structure of the individual items in the list.
struct myListItemStruct {
    int guid;                           // a unique id to identify the list item
    char name[128];                     // a name to represent the item
    unsigned char *data;                // arbitrary data 'payload'
    int size;                           // size of data
    struct myListItemStruct *next_item; // pointer to next item
};

// Define an own type for shorter declarations
typedef struct myListItemStruct itemType;

// create_item:
// Creates and initializes a new item, or returns NULL, if it could not allocate memory.
itemType *create_item() {
    static int guid_ctr = 0; // static counter to create unique ids
    itemType *ptr;

    ptr = malloc(sizeof(itemType)); // Allocate memory for the list item
    if (ptr != NULL) {
        ptr->guid = guid_ctr++; // Generate a unique ID
        printf("Enter name: \n");
        scanf("%s", ptr->name); // Enter a name
        ptr->size = 1000;
        ptr->data = malloc(ptr->size * sizeof(unsigned char)); // Allocate some memory for a payload
        if (ptr->data == NULL) {
            free(ptr);
            return NULL; // Return NULL if allocation as failed
        }
    }
    return ptr; // Return pointer to the new item
}

// Insert_item:
// Inserts an existing item into the (potentially empty) list
void insert_item(itemType *new_item, itemType **list_ptr) {
    new_item->next_item = *list_ptr; // Append existing list to new item
    *list_ptr = new_item;            // Set list_ptr to points to new item
}

// print all items
void print_items(itemType *list_start) {
    itemType *current = list_start;
    while (current != NULL) {
        printf("Name: %s, Address: %p, Next: %p\n", current->name, (void *)current, (void *)current->next_item);
        current = current->next_item;
    }
}

// Finds an item with guid in the list
itemType *find_item(int guid, itemType *list_start) {
}

// Deletes an item and returns the successor of the deleted item
// The chaining of the previous and next element has to be done
// by the caller.
itemType *simple_delete_item(itemType *item) {
}

// Complete delete item
// Deletes item 'to_delete' from the 'list'
// return 0, if the item does not exist in the list, otherwise 1
int delete_item(itemType *to_delete, itemType **list_ptr) {
    // TO DO: Check if list (i.e. *list_ptr) is not NULL
    // TO DO: Check special case, if first list element is to be deleted
    //        The list_ptr needs to be changed, to point to second list element
    // TO DO: General case: move through list with a helper pointer
    // TO DO: Don't forget to free the memory of the list element and its data payload
}

// scanner
void scannerMenu(int *choice) {
    char input[100];
    if (fgets(input, sizeof(input), stdin)) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i])) {
                *choice = input[i] - '0'; // Convert character to integer
                return;
            }
        }
    }
    *choice = -1; // Set choice to -1 if no valid number is found
}

itemType *my_list = NULL; // Declare my_list as a global variable

// menu options & input checking
void menu() {
    int choice = -1;
    printf("Choose an option by entering the number: \n");
    printf("1. Add new entry to list!\n");
    printf("2. Print all added entries!\n");
    scannerMenu(&choice);

    if (choice != -1) {
        printf("You chose option: %d\n", choice);
    } else {
        printf("Invalid input!!!\n");
    }

    switch (choice) {
    case 1: {
        itemType *new_item = create_item(); // Create and initialize a new item
        insert_item(new_item, &my_list);    // Insert the new item into the list
        printf("Item added to the list.\n");
    } break;
    case 2: {
        print_items(my_list); // Print all items in the list
    } break;

    default:
        printf("Invalid choice. Please enter 1 or 2.\n");
        break;
    }
}

int main() {
    menu();
    return 0;
}
