
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "contact_input.h"

struct Address_book *menu (struct Address_book *address_book_head, int *interrupt);

int main()
{
    volatile int interrupt = 0;
    struct Address_book *address_book_head = NULL;
    while (interrupt!=1){
        address_book_head = menu (address_book_head, &interrupt);
    }
    return 0;
}

struct Address_book *menu (struct Address_book *address_book_head, int *interrupt)
{   
    int index = 0;
    int choice = 0;
    char name [NAMELENGTH];
    char phone_number [NUMBERLENGTH];
    printf("\n[1] New contact\n");
    printf("[2] Delete contact\n");
    printf("[3] Display address book\n");
    printf("[4] Search for contact\n");
    printf("[5] Add contact after\n");
    printf("[6] Import constacts from file\n");
    printf("[7] Exit program\n");
    printf("Enter your choice 1-7: ");
    if (scanf("%d", &choice)== 0) {
        clear_cosole();
        printf("\n**Invalid Input.**\n");
        choice=0;
        return address_book_head;
    }
    clear_cosole();
    switch (choice){
        case 1:
            printf ("\nInput contact name: ");
            get_user_input (name,NAMELENGTH);
            printf ("Input phone number: ");
            get_user_input (phone_number,NUMBERLENGTH);
            address_book_head = insert_contact(address_book_head,create_contact (name, phone_number));
            break;
        case 2:
            printf ("\nInput name of the addres you want to delete: ");
            get_user_input (name,NAMELENGTH);
            address_book_head = delete_contact(address_book_head, name);
            break;
        case 3:
            display_address_book(address_book_head);
            break;
        case 4:
            printf ("\nInput name of the addres you want to search for: ");
            get_user_input (name,NAMELENGTH);
            search_for_contact(address_book_head, name);
            break;
        case 5:
            index = get_index();
            if (index == 0){
                printf("\n**Invalid Input.**\n");
            }
            else {
                printf ("\nInput contact name: ");
                get_user_input (name,NAMELENGTH);
                printf ("Input phone number: ");
                get_user_input (phone_number,NUMBERLENGTH);
                insert_contact_after(address_book_head,create_contact (name, phone_number),index);
            }
            break;
         case 6:
            address_book_head = read_contacts_from_file(address_book_head);
            printf ("\nContacts read from file\n");
            break;
        case 7:
            printf ("\nCleaning up program memmory before closing");
            address_book_head = cleanup(address_book_head);
            *interrupt = 1;
            break;
        default:
            printf("\n**Invalid Input.**\n");
    }
  return address_book_head;
}