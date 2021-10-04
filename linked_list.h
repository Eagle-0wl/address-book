#define NAMELENGTH 50
#define NUMBERLENGTH 50

struct Address_book
{
    char name[NAMELENGTH];
    char phone_number[NUMBERLENGTH];
    struct Address_book *next;
};

void insert_address(struct Address_book **address_book_head);
void delete_address(struct Address_book **address_book_head);
void display_address(struct Address_book **address_book_head);
void search_address(struct Address_book **address_book_head);
void cleanup(struct Address_book **address_book_head); 