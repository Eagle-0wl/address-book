#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "user_input.h"

//creates contact node from user inputs
struct Address_book *create_contact (){
    struct Address_book *new_node = (struct Address_book*) malloc(sizeof(struct Address_book));
    printf ("\nInput contact name: ");
    get_user_input (new_node->name,NAMELENGTH);

    printf ("Input phone number: ");
    get_user_input (new_node->phone_number,NUMBERLENGTH);
    return new_node;
};

// Function goes through whole list and searchers for node with same name and returns pointer to it
struct Address_book *search_node_in_list(struct Address_book *address_book_head, char *name, int *position)
{
    *position = 1;
    struct Address_book *ptr =  address_book_head;
    while(ptr != NULL) {                        //through whole list
        if (strcmp(ptr->name,name) == 0){       //check if element with that name exist  
            return ptr;
        }
        *position+=1;
        ptr = ptr->next;
    }
    return NULL;
};

// Function to handle dublicate insertion
void contact_colision (struct Address_book *current, struct Address_book *new_node, int position)
{
    char input;
    printf ("There is already and contact with same name [%d] %s %s. Do you want to update it with new info? [y/n]: ",position, current->name, current->phone_number);
    input = fgetc(stdin);
    fflush (stdin);
    if (input == 'y' || input == 'Y'){
        memset(current->phone_number, '\0', sizeof(char)*NUMBERLENGTH);
        strncpy(current->phone_number, new_node->phone_number, NUMBERLENGTH);
        free (new_node);
        clear_cosole();
        printf ("Address info updated: %s %s", current->name, current->phone_number);
        return;
    }
    else{
        free (new_node);
        clear_cosole();
        return;
    }
}

// Function goes through whole list and inserts node in sorted order by address name
struct Address_book * insert_contact(struct Address_book *address_book_head)
{
    int position;
    struct Address_book *current;
    struct Address_book *ptr = NULL;
    struct Address_book * new_node  = create_contact ();

    ptr = search_node_in_list(address_book_head,new_node->name,&position);
    if (ptr != NULL){
        printf ("Adrress with that name found: [%d] %s %s \n",position, ptr->name, ptr->phone_number); //if node exist display it's info
        contact_colision (ptr, new_node, position);
        return address_book_head;
    }
    //Check if item has to be inserted as a first element
    if (address_book_head == NULL || strcmp((address_book_head)-> name,new_node->name) > 0) {
        new_node->next = address_book_head;
        address_book_head = new_node;
    }
    else {
        //Find location where to insert the node
        current = address_book_head;
        while (current->next != NULL && strcmp(current->next->name,new_node->name) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    return address_book_head;
};

// Function finds and removes node from linked list
struct Address_book * remove_node_from_linked_list (struct Address_book *address_book_head, char *name, int *rc)
{
    struct Address_book *temp = address_book_head;
    struct Address_book *prev;
    // Check if head node is the address to be deleted
    if (temp != NULL && strcmp(temp->name,name) == 0) {
        address_book_head = temp->next; // Changed head
        free(temp); // free old head
        *rc = 0;
        return address_book_head;
    }
    // Search for the address to be deleted, keep track of the previous node so we can relink list when node is removed
    while (temp != NULL && strcmp(temp->name,name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    // If address was not present in linked list
    if (temp == NULL){
        *rc = 1;
        return address_book_head;
    }
    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
    *rc = 0;
    return address_book_head;
}

// Function to delete user specified node
struct Address_book * delete_contact(struct Address_book *address_book_head)
{   
    int rc = 0;
    char name [NAMELENGTH];
    printf ("\nInput name of the addres you want to delete: ");
    fgetc(stdin);
    get_user_input (name,NAMELENGTH);
    address_book_head = remove_node_from_linked_list (address_book_head, name, &rc);
    if (rc == 0){
        printf ("\nContact %s deleted\n", name);
    }
    else{
        printf ("\nContact %s not found\n", name);
    }
    return address_book_head;
};

// Function goes through whole list and displays all nodes in a list ant their content
void display_address_book(struct Address_book *address_book_head)
{
    int counter = 1;
    if (address_book_head != NULL)
        printf ("\nAddress book:\n");
    else
        printf ("\nAddress bookis empty\n");
    while(address_book_head != NULL) {                 //start from the beginning
        printf ("[%d] %s %s \n",counter, address_book_head->name, address_book_head->phone_number);
        counter++;
        address_book_head = address_book_head->next;
    }
};

//gets user input on what address to search for
void search_for_contact(struct Address_book *address_book_head)
{
    int position;
    char name [NAMELENGTH];
    struct Address_book *ptr = NULL;
    printf ("\nInput name of the addres you want to search for: ");
    fgetc(stdin);
    get_user_input (name,NAMELENGTH);
    ptr = search_node_in_list(address_book_head,name,&position);
    if (ptr != NULL){
        printf ("Adrress found: %s %s \n", ptr->name, ptr->phone_number); //if node exist display it's info
    }
    else{
        printf ("Address not found");
    }
};

// Function goes through whole list and deletes all the nodes
struct Address_book *cleanup(struct Address_book *address_book_head)
{
    struct Address_book *tmp;
    struct Address_book *head = address_book_head;
    while(head != NULL) { 
        tmp = head;
        head = head->next;
        free (tmp);
    }
    return address_book_head = NULL;
};

//Function inserts new contact at specific position in list if possible
struct Address_book * insert_contact_after (struct Address_book *address_book_head, struct Address_book *new_node, int index)
{
    int position;
    int counter = 1;
    struct Address_book *current = address_book_head;
    struct Address_book *ptr = NULL;
    if (current == NULL){
        printf ("Can't insert contant, because address book is empty");
        return;
    }

    ptr = search_node_in_list(address_book_head,new_node->name,&position);
    if (ptr != NULL){
        printf ("Adrress with that name found:[%d] %s %s \n",position, ptr->name, ptr->phone_number); //if node exist display it's info
        contact_colision (current, new_node, position);
        return address_book_head;
    }

    while (counter != index && current->next != NULL){
        current = current->next;
        counter++;
        if (strcmp(current->name,new_node->name) == 0) {
            contact_colision (current, new_node, position);
            return address_book_head;
        }
    }
    if (counter < index){
        printf ("There is only %d contacts in address book", counter);
    }
    else if (counter == index){
        if (current->next == NULL){
            current->next = new_node;
            new_node->next = NULL;
        }
        else {
            new_node->next = current->next;
            current->next = new_node;
        }   
    }
    return address_book_head;
};