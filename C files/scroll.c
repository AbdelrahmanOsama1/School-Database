#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "scroll.h"
#include "sounds.h"

void print_YorN_Options(int selected) {
    system("cls"); // Clear the screen

    char* options[2] = {"CONTINUE", "BACK TO MAIN MENU"};
    for (int i = 0; i < 2; i++) {
        if (i == selected) {
printf("\n  ");
printf("\033[7;33m%s\033[m\n", options[i]);
        }
        else {
            printf("\n  ");
            printf("%s\n", options[i]);
        }

    }
            move_sound();

}

/**********************************************************************************/

int YorN_scroll(void){


    int choice = 0;
    int key;
    int selected = 0;

    do {
        print_YorN_Options(selected);

        key = _getch(); // Get user input

        switch (key) {
            case 224: // Arrow key prefix
                key = _getch(); // Get the actual key
                switch (key) {
                    case 72: // Up arrow key
                        if (selected > 0)
                            selected--;
                        break;
                    case 80: // Down arrow key
                        if (selected < 1)
                            selected++;
                        break;
                }
                break;
            case 13: // Enter key
                choice = selected + 1;
                select_sound();
                break;

        }

    } while (choice == 0);

    system("cls"); // Clear the screen again
    return choice;
}

/**********************************************************************************/

void print_Edit_Options(int selected) {
    system("cls"); // Clear the screen

    printf("\033[7;37m\n\n\t\t\t     >> WHAT DO YOU WANT TO EDIT ?  <<     \n\n\033[m\n");

    char* options[7] = {" 1- Name.", " 2- Age." ," 3- Phone.", " 4- ID."," 5- Arabic Mark.", " 6- English Mark.", " 7- EXIT."};
    for (int i = 0; i < 7; i++) {
        if (i == selected) {
printf("\n  ");
printf("\033[7;33m%s\033[m\n", options[i]);
        }
        else {
            printf("\n  ");
            printf("%s\n", options[i]);
        }
    }
                move_sound();

}

/**********************************************************************************/

int Edit_scroll(void){


    int choice = 0;
    int key;
    int selected = 0;

    do {
        print_Edit_Options(selected);

        key = _getch(); // Get user input

        switch (key) {
            case 224: // Arrow key prefix
                key = _getch(); // Get the actual key
                switch (key) {
                    case 72: // Up arrow key
                        if (selected > 0)
                            selected--;
                        break;
                    case 80: // Down arrow key
                        if (selected < 6)
                            selected++;
                        break;
                }
                break;
            case 13: // Enter key
                choice = selected + 1;
                                select_sound();
                break;
        }

    } while (choice == 0);

    system("cls"); // Clear the screen again
    return choice;
}


/**********************************************************************************/

void print_school_Options(int selected) {
    system("cls"); // Clear the screen
    printf("\033[7;37m\n\n\t\t\t     >> HOW DO YOU WANT TO SORT THE STUDENTS' NAMES ?  <<     \n\n\033[m\n");

    char* options[6] = {" 1- Name.", " 2- Age." ," 3- ID.", " 4- Arabic Mark.", " 5- English Mark.", " 6- EXIT."};
    for (int i = 0; i < 6; i++) {
        if (i == selected) {
printf("\n  ");
printf("\033[7;33m%s\033[m\n", options[i]);
        }
        else {
            printf("\n  ");
            printf("%s\n", options[i]);
        }
    }
                move_sound();

}

/**********************************************************************************/

int print_school_scroll(void){


    int choice = 0;
    int key;
    int selected = 0;

    do {
        print_school_Options(selected);

        key = _getch(); // Get user input

        switch (key) {
            case 224: // Arrow key prefix
                key = _getch(); // Get the actual key
                switch (key) {
                    case 72: // Up arrow key
                        if (selected > 0)
                            selected--;
                        break;
                    case 80: // Down arrow key
                        if (selected < 5)
                            selected++;
                        break;
                }
                break;
            case 13: // Enter key
                choice = selected + 1;
                                select_sound();
                break;
        }

    } while (choice == 0);

    system("cls"); // Clear the screen again
    return choice;
}

/**********************************************************************************/

void print_Main_Options(int selected) {
    system("cls"); // Clear the screen

printf("\033[7;37m\n\n\t\t\t     >> HELLO , PLEASE CHOOSE FROM THE BELOW LIST <<     \n\n\033[m\n");

//printf("\n\n\t\t\t     >> HELLO , PLEASE CHOOSE FROM THE BELOW LIST <<\n\n");

    char* options[7] = {" 1- ADD STUDENT.", " 2- EDIT STUDENT." ," 3- PRINT STUDENT INFORMATION.", " 4- PRINT SCHOOL."," 5- REMOVE STUDENT.", " 6- CALL STUDENT.", " 7- EXIT."};
    for (int i = 0; i < 7; i++) {
        if (i == selected) {
printf("\n  ");
printf("\033[7;33m%s\033[m\n", options[i]);
        }
        else {
            printf("\n  ");
            printf("%s\n", options[i]);
        }
    }
                move_sound();

}

/**********************************************************************************/

int main_scroll(void){


    int choice = 0;
    int key;
    int selected = 0;

    do {
        print_Main_Options(selected);

        key = _getch(); // Get user input

        switch (key) {
            case 224: // Arrow key prefix
                key = _getch(); // Get the actual key
                switch (key) {
                    case 72: // Up arrow key
                        if (selected > 0)
                            selected--;
                        break;
                    case 80: // Down arrow key
                        if (selected < 6)
                            selected++;
                        break;
                }
                break;
            case 13: // Enter key
                choice = selected + 1;
                                select_sound();
                break;
        }

    } while (choice == 0);

    system("cls"); // Clear the screen again
    return choice;
}


/**********************************************************************************/


/*

Black: \033[30m
Red: \033[31m
Green: \033[32m
Yellow: \033[33m
Blue: \033[34m
Magenta: \033[35m
Cyan: \033[36m
White: \033[37m

Background Colors:

Black: \033[40m
Red: \033[41m
Green: \033[42m
Yellow: \033[43m
Blue: \033[44m
Magenta: \033[45m
Cyan: \033[46m
White: \033[47m
Other Formatting:

Reset All: \033[0m
Bold: \033[1m
Underline: \033[4m
Blink: \033[5m
Reverse Video: \033[7m
Reset Bold/Underline/Blink: \033[21m, \033[24m, \033[25m
Reset Reverse Video: \033[27m

*/
