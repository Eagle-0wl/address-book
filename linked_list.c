#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>
#include <string.h>

void insert_address(struct Address_book **address_book_head)
{
    struct Address_book *new_node = (struct Address_book*) malloc(sizeof(struct Address_book));
    struct Address_book *ptr = *address_book_head;

    printf ("\nInput address name: ");
    fgetc(stdin); 
    fgets(new_node->name, NAMELENGTH, stdin);
    new_node->name[strcspn(new_node->name, "\n")] = 0;

    printf ("Input phone number: ");
    fgets(new_node->phone_number, NUMBERLENGTH, stdin);
    new_node->phone_number[strcspn(new_node->phone_number, "\n")] = 0;


    struct Address_book* current;
    /* Special case for the head end */
    if (*address_book_head == NULL || strcmp((*address_book_head)-> name,new_node->name) > 0) {
        new_node->next = *address_book_head;
        *address_book_head = new_node;
    }
    else {
        /* Locate the node before the point of insertion */
        current = *address_book_head;
        while (current->next != NULL && strcmp(current->next->name,new_node->name) < 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
};

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
        return;
    }
    // Search for the address to be deleted, keep track of the previous node as we need to change 'prev->next'
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

void display_address(struct Address_book **address_book_head)
{
    struct Address_book *ptr = *address_book_head;
    if (ptr != NULL)
        printf ("\nAddress book:\n");
    else
        printf ("\nAddress bookis empty\n");
    while(ptr != NULL) {                 //start from the beginning
        printf ("%s: %s \n", ptr->name, ptr->phone_number);
        ptr = ptr->next;
    }
};

void search_address(struct Address_book **address_book_head)
{
    char name [NAMELENGTH];
    int counter = 0;
    struct Address_book *ptr = *address_book_head;
    if (ptr == NULL){
        printf ("Address book is empty");
        return;
    }

    printf ("\nInput name of the addres you want to search for: ");
    fgetc(stdin); 
    fgets(name, NAMELENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    while(ptr != NULL) {
        if (strcmp(ptr->name,name) == 0){
            printf ("Adrress found: %s %s \n", ptr->name, ptr->phone_number);
            counter++;
            break;
        }
        ptr = ptr->next;
    }
    if (counter == 0){
        printf ("Address not found");
    }
};

void cleanup(struct Address_book **address_book_head)
{
    struct Address_book *tmp;
    struct Address_book *head = *address_book_head;
    while(head != NULL) { 
        tmp = head;
        head = head->next;
        memset(tmp, 0, sizeof(struct Address_book));
        free (tmp);
    }
    *address_book_head = NULL;
};
