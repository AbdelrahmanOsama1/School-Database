#include <stdio.h>
#include <stdlib.h>
#include "file_handling.h"
#include <windows.h>
// #include "features.h"  (included in additional funcs.h)
#include "additional_funcs.h"
#include "scroll.h"
#include "sounds.h"
#include <unistd.h>


int main() {

    load_students();

    while(1){

    int choice = main_scroll();

    if(choice==1){
        add_student();
    }
    else if(choice==2){
        edit_student();
    }
    else if(choice==3){
        student_print();
    }
    else if(choice==4){
        school_print();
    }
    else if(choice==5){
        remove_student();
    }
    else if(choice==6){
        call_student();
    }
    else if(choice==7){
printf("\n\n\n\n\n\n\n\n\n\n");
printf("                _  _       _____ ____  _____ _____     ____   _    _     _____ ____ _____ ___ _   _ _____\n");
Sleep(500);
printf("              _| || |_    |  ___|  _ \\| ____| ____|   |  _ \\ / \\  | |   | ____/ ___|_   _|_ _| \\ | | ____|\n");
Sleep(500);
printf("             |_  ..  _|   | |_  | |_) |  _| |  _|     | |_) / _ \\ | |   |  _| \\___ \\ | |  | ||  \\| |  _|\n");
Sleep(500);
printf("             |_  ..  _|   |  _| |  _ <| |___| |___    |  __/ ___ \\| |___| |___ ___) || |  | || |\\  | |___\n");
Sleep(500);
printf("               |_||_|     |_|   |_| \\_\\_____|_____|___|_| /_/   \\_\\_____|_____|____/ |_| |___|_| \\_|_____|\n");
Sleep(500);
printf("                                                 |_____|\n");

Sleep(4000);
system("cls");
        break;
    }

    }


    return 0;
}


