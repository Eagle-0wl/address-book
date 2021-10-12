#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
//clears console from leftover input
void clear_cosole(){
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { };    //get left over input if user had more thant one character input
}

// Function gets user input string and removes new line from it
void get_user_input (char *name,int lenght)
{
    memset(name, '\0', sizeof(char)*lenght);
    fgets(name, lenght, stdin);         //get user input
    name[strcspn(name, "\n")] = 0;      //remove new line from string
}
//gets location where to insert contact from user
int get_index()
{
    int index = 0;
    printf ("\nInput contact position [1-99999999] after which address will be placed: ");
    if (scanf("%8d", &index) == 0) {
        clear_cosole();
        printf("\n**Invalid Input.**\n");
        return 0;
    }
    clear_cosole();
    if (index == 0){
        printf("\n**Invalid Input.**\n");
        return 0;
    }
    return index;
}

//reads and inserts contacts to list
struct Address_book *read_contacts_from_file(struct Address_book *address_book_head)
{
    char *filename = "contacts";   //config file location
    char name[NAMELENGTH];
    char phone_number[NUMBERLENGTH];

    FILE *file;    
    file=fopen(filename,"r");               //opening file for read operation
    if (file == NULL)                       //check if file opend
        {   
            printf("Error! Could not open file"); 
        }
    while (fscanf(file, " %50s", name) ==1 && fscanf(file, " %20s", phone_number)== 1) {
        address_book_head = insert_contact(address_book_head,create_contact (name, phone_number));
        memset(name, '\0', sizeof(char)*NAMELENGTH);
        memset(phone_number, '\0', sizeof(char)*NUMBERLENGTH);
    }
    fclose(file);
    return address_book_head;
};
