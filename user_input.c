#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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