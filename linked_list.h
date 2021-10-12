#define NAMELENGTH 50
#define NUMBERLENGTH 20

struct Address_book
{
    char name[NAMELENGTH];
    char phone_number[NUMBERLENGTH];
    struct Address_book *next;
};
//creates contact node from user inputs
struct Address_book *create_contact (char *name, char *phone_number);

// Function goes through whole list and searchers for node with same name and returns pointer to it
struct Address_book *search_node_in_list(struct Address_book *address_book_head, char *name, int *position);

// Function to handle dublicate insertion
void contact_colision (struct Address_book *current, struct Address_book *new_node, int position);

// Function goes through whole list and inserts node in sorted order by address name
struct Address_book * insert_contact(struct Address_book *address_book_head, struct Address_book *new_node);

// Function finds and removes node from linked list
struct Address_book *remove_node_from_linked_list (struct Address_book *address_book_head, char *name, int *rc);

// Function to delete user specified node
struct Address_book *delete_contact(struct Address_book *address_book_head, char *name);

// Function goes through whole list and displays all nodes in a list ant their content
void display_address_book(struct Address_book *address_book_head);

//gets user input on what address to search for
void search_for_contact(struct Address_book *address_book_head, char *name);

// Function goes through whole list and deletes all the nodes
struct Address_book *cleanup(struct Address_book *address_book_head);

//Function inserts new contact at specific position in list if possible
struct Address_book * insert_contact_after (struct Address_book *address_book_head, struct Address_book *new_node, int index);