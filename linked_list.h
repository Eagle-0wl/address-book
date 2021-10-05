#define NAMELENGTH 50
#define NUMBERLENGTH 20

struct Address_book
{
    char name[NAMELENGTH];
    char phone_number[NUMBERLENGTH];
    struct Address_book *next;
};

// Function gets user input string and removes new line from it
void get_user_input (char *name,int lenght);

// Function goes through whole list and searchers for node with same name and returns pointer to it
struct Address_book *search_node_in_list(struct Address_book **address_book_head, char name);

// Function to handle dublicate insertion
void contact_colision (struct Address_book *current, struct Address_book *new_node);

// Function goes through whole list and inserts node in sorted order by address name
void insert_contact(struct Address_book **address_book_head);

// Function finds and removes node from linked list
int remove_node_from_linked_list (struct Address_book **address_book_head, char *name);

// Function to delete user specified node
void delete_contact(struct Address_book **address_book_head);

// Function goes through whole list and displays all nodes in a list ant their content
void display_address_book(struct Address_book **address_book_head);

//gets user input on what address to search for
void search_for_contact(struct Address_book **address_book_head);

// Function goes through whole list and deletes all the nodes
void cleanup(struct Address_book **address_book_head);