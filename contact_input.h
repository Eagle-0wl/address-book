//clears console from leftover input
void clear_cosole();

// Function gets user input string and removes new line from it
void get_user_input (char *name,int lenght);

//gets location where to insert contact from user
int get_index();

//reads and inserts contacts to list
struct Address_book *read_contacts_from_file(struct Address_book *address_book_head);
