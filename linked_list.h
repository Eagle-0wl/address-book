#define NAMELENGTH 50
#define NUMBERLENGTH 20

struct Address_book
{
    char name[NAMELENGTH];
    char phone_number[NUMBERLENGTH];
    struct Address_book *next;
};
// Function goes through whole list and inserts node in sorted order by address name
void insert_address(struct Address_book **address_book_head);
// Function to delete user specified node
void delete_address(struct Address_book **address_book_head);
// Function goes through whole list and displays all nodes in a list ant their content
void display_address(struct Address_book **address_book_head);
// Function goes through whole list and searchers for node with same name as user input
void search_address(struct Address_book **address_book_head);
// Function goes through whole list and deletes all the nodes
void cleanup(struct Address_book **address_book_head); 