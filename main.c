
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "user_input.h"

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
    printf("\n[1] New contact\n");
    printf("[2] Delete contact\n");
    printf("[3] Display address book\n");
    printf("[4] Search for contact\n");
    printf("[5] Add contact after\n");
    printf("[6] Exit program\n");
    printf("Enter your choice 1-6: ");
    if (scanf("%d", &choice)== 0) {
        fgetc(stdin);
        printf("\n**Invalid Input.**\n");
        choice=0;
        return 0;
    }
    fflush (stdin);
    switch (choice){
        case 1:
            fgetc(stdin);
            address_book_head = insert_contact(address_book_head);
            break;
        case 2:
            address_book_head = delete_contact(address_book_head);
            break;
        case 3:
            display_address_book(address_book_head);
            break;
        case 4:
            search_for_contact(address_book_head);
            break;
        case 5:
            index = get_index();
            if (index == 0){
                printf("\n**Invalid Input.**\n");
            }
            else {
                insert_contact_after(address_book_head,create_contact (),index);
            }
            break;
        case 6:
            address_book_head = cleanup(address_book_head);
            *interrupt = 1;
            break;
        default:
            printf("\n**Invalid Input.**\n");
    }
  return address_book_head;
}
