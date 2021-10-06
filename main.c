
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int menu();

int main()
{
    volatile int interrupt = 0;
    struct Address_book *address_book_head = NULL;
    while (interrupt!=1){
        interrupt = menu (&address_book_head);
    }

    return 0;
}

int menu (struct Address_book **address_book_head)
{
    int choice = 0;
    printf("\n[1] New contact\n");
    printf("[2] Delete contact\n");
    printf("[3] Display address book\n");
    printf("[4] Search for contact\n");
    printf("[5] Add contact after\n");
    printf("[6] Exit program\n");
    printf("Enter your choice 1-5: ");
    if (scanf("%d", &choice)== 0) {
        fgetc(stdin);
        printf("\n**Invalid Input.**\n");
        choice=0;
        return 0;
    }
    fflush (stdin);
    switch (choice){
        case 1:
            insert_contact(address_book_head);
            break;
        case 2:
            delete_contact(address_book_head);
            break;
        case 3:
            display_address_book(address_book_head);
            break;
        case 4:
            search_for_contact(address_book_head);
            break;
        case 5:
            add_contact_after (address_book_head);
            break;
        case 6:
            cleanup(address_book_head);
            return 1;
            break;
        default:
            printf("\n**Invalid Input.**\n");
    }
  return 0;
}
