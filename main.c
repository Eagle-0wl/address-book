
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
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

int menu (struct Address_book *address_book_head)
{
    int choice = 0;
    printf("\n[1] New address\n");
    printf("[2] Delete address\n");
    printf("[3] Display address book\n");
    printf("[4] Search for address\n");
    printf("[5] Exit program\n");
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
            insert_address(address_book_head);
            break;
        case 2:
            delete_address(address_book_head);
            break;
        case 3:
            display_address(address_book_head);
            break;
        case 4:
            search_address(address_book_head);
            break;
        case 5:
            cleanup(address_book_head);
            return 1;
            break;
        default:
            printf("\n**Invalid Input.**\n");
    }
  return 0;
}