#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// Function goes through whole list and inserts node in sorted order by address name
void insert_address(struct Address_book **address_book_head)
{
    struct Address_book *new_node = (struct Address_book*) malloc(sizeof(struct Address_book));
    struct Address_book *current;
    struct Address_book *tmp;
    char input;
    printf ("\nInput address name: ");
    fgetc(stdin); 
    fgets(new_node->name, NAMELENGTH, stdin);
    new_node->name[strcspn(new_node->name, "\n")] = 0;
    
    printf ("Input phone number: ");
    fgets(new_node->phone_number, NUMBERLENGTH, stdin);
    new_node->phone_number[strcspn(new_node->phone_number, "\n")] = 0;


    //Check if item has to be inserted as a first element
    if (*address_book_head == NULL || strcmp((*address_book_head)-> name,new_node->name) > 0) {
        new_node->next = *address_book_head;
        *address_book_head = new_node;
    }
    else {
        //Find location where to insert the node
        current = *address_book_head;
        while (current->next != NULL && strcmp(current->next->name,new_node->name) < 0) {
            current = current->next;
        }
        if (strcmp(current->name,new_node->name) == 0){
            printf ("There is already and address with same name. Do you want to update it with new info? [y/n]: ");
            input = fgetc(stdin);
            fflush (stdin);
            if (input == 'y' || input == 'Y'){
                strncpy(current->name, new_node->name, 50);
                strncpy(current->phone_number, new_node->phone_number, 20);
                free (new_node);
                while ((input = getchar()) != '\n' && input != EOF) { };    //get left over input if user had more thant one character input
                printf ("Address info updated: %s %s", current->name, current->phone_number);
                return;
            }
            else{
                free (new_node);
                while ((input = getchar()) != '\n' && input != EOF) { };    //get left over input if user had more thant one character input
                return;
            }
        }
        new_node->next = current->next;
        current->next = new_node;
    }
};
// Function to delete user specified node
void delete_address(struct Address_book **address_book_head)
{
    char name [NAMELENGTH];
    int counter = 0;
    struct Address_book *temp = *address_book_head;
    struct Address_book *prev;
    printf ("\nInput name of the addres you want to search for: ");
    fgetc(stdin); 
    fgets(name, NAMELENGTH, stdin);
    name[strcspn(name, "\n")] = 0;
 
    // Check if head node is the address to be deleted
    if (temp != NULL && strcmp(temp->name,name) == 0) {
        *address_book_head = temp->next; // Changed head
        free(temp); // free old head
        printf ("Adrress %s deleted\n", name);
        return;
    }
    // Search for the address to be deleted, keep track of the previous node so we can relink list when node is removed
    while (temp != NULL && strcmp(temp->name,name) != 0) {
        prev = temp;
        temp = temp->next;
    }
 
    // If address was not present in linked list
    if (temp == NULL){
        printf ("Address not found");
        return;
    }
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    printf ("Adrress %s deleted\n", name);
};
// Function goes through whole list and displays all nodes in a list ant their content
void display_address(struct Address_book **address_book_head)
{
    struct Address_book *ptr = *address_book_head;
    if (ptr != NULL)
        printf ("\nAddress book:\n");
    else
        printf ("\nAddress bookis empty\n");
    while(ptr != NULL) {                 //start from the beginning
        printf ("%s %s \n", ptr->name, ptr->phone_number);
        ptr = ptr->next;
    }
};

// Function goes through whole list and searchers for node with same name as user input
void search_address(struct Address_book **address_book_head)
{
    char name [NAMELENGTH];
    int counter = 0;
    struct Address_book *ptr = *address_book_head;
    //check if list is empty
    if (ptr == NULL){
        printf ("Address book is empty");
        return;
    }
    
    printf ("\nInput name of the addres you want to search for: ");
    fgetc(stdin);                       //catch unwanted symbols, so user input won't be skiped
    fgets(name, NAMELENGTH, stdin);     //get user input
    name[strcspn(name, "\n")] = 0;      //remove new line from string

    while(ptr != NULL) {                        //through whole list
        if (strcmp(ptr->name,name) == 0){       //check if element with that name exist
            printf ("Adrress found: %s %s \n", ptr->name, ptr->phone_number); //if node exist dispaly it's info
            counter++;
            break;
        }
        ptr = ptr->next;
    }
    if (counter == 0){
        printf ("Address not found");
    }
};
// Function goes through whole list and deletes all the nodes
void cleanup(struct Address_book **address_book_head)
{
    struct Address_book *tmp;
    struct Address_book *head = *address_book_head;
    while(head != NULL) { 
        tmp = head;
        head = head->next;
        free (tmp);
    }
    *address_book_head = NULL;
};
