// #include "features.h"  (included in additional funcs.h)
#include "additional_funcs.h"
#include <windows.h>
#include "scroll.h"
#include "sounds.h"

 int num_of_students;   // global
 student_t* school;     // global  (reserve for one student)

// ADD STUDENT

void add_student(void){

    while(1){

    FILE *file = fopen("students.dat", "a+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    num_of_students ++ ;
    school = (student_t*)realloc(school , (num_of_students * sizeof(student_t)));

    add_name();

    add_age();

    add_unique_phone_number();       // UNIQUE

    add_unique_id();           // UNIQUE

    add_arabic_mark();     // not unique

    add_english_mark();    // not unique


    fprintf(file, "%s %d %s %s %d %d\n", school[num_of_students - 1].Name, school[num_of_students - 1].Age , school[num_of_students - 1].Phone, school[num_of_students - 1].ID, school[num_of_students - 1].Ara_mark, school[num_of_students - 1].E_mark);

    fclose(file);


    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){
        system("cls");
        break;
    }
}

    }

/*********************************************************************************************************************************************************************************/

// edit student

void edit_student(void){

    int target_index=-1,i,choice2;

    if(num_of_students == 0){
        system("cls");
        printf("\n>> THERE ARE NO STUDENTS , press any key to back to main menu\n");
        error_sound();
        getch();
        system("cls");
    }
    else{
target_index = check_id();
    }

        while(1){


            while(1){

        if(num_of_students == 0){
        break;
    }

        system("cls");

         choice2 = Edit_scroll();


        if(choice2 == 1){

                name_edit(target_index);
                break;
        }
        else if(choice2==2){

                age_edit(target_index);
                break;
        }




        else if(choice2==3){   // phone is UNIQUE
                edit_phone_number(target_index);
                break;
        }



        else if(choice2==4){      // id is UNIQUE
                edit_id(target_index);
                break;
        }



        else if(choice2==5){

                ara_edit(target_index);
                break;
        }
        else if(choice2==6){

                eng_edit(target_index);
                break;
        }
        else if(choice2==7){

                break;
        }

        else{
                    system("cls");
                    printf("\n>> ERROR SELECTION !!!  press any key to try again\n");
                    error_sound();
                    getch();
                    system("cls");

        }


            }

            system("cls");

    if((num_of_students == 0)||(choice2==7)){

        break;
    }

    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){

    system("cls");


    // overwrite the file with the all data after editing

    FILE *file = fopen("students.dat", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i=0;i<num_of_students;i++) {

    fprintf(file, "%s %d %s %s %d %d\n", school[i].Name, school[i].Age , school[i].Phone, school[i].ID, school[i].Ara_mark, school[i].E_mark);

    }
    fclose(file);

                break;
            }

        }


}


/*********************************************************************************************************************************************************************************/

// print student

void student_print(void){

    int target_index=-1;

    while(1){





    if(num_of_students == 0){
        system("cls");
        printf("\n>> THERE ARE NO STUDENTS , press any key to back to main menu\n");
         error_sound();
        getch();
        system("cls");
        break;
    }
    else{

    target_index = check_id();
    system("cls");

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);

printf("%c             Name              %c  Age  %c    phone    %c  id   %c Arabic Mark %c English Mark%c\n",221,221,221,221,221,221,222);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);
printf("%c ",186);

printf("%-30s",school[target_index].Name);

printf("%c  %-5d%c",186,school[target_index].Age,186);

printf(" %-12s%c",school[target_index].Phone,186);

printf(" %-6s%c",school[target_index].ID,186);

printf("     %-8d%c",school[target_index].Ara_mark,186);

printf("     %-7d",school[target_index].E_mark);
printf(" %c",186);

printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


            printf("\n\n");
            printf(">> press any key to back\n");
            getch();

    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){
        system("cls");
        break;
    }



}
    }
}

/*********************************************************************************************************************************************************************************/

// print school

void school_print(void){
    int i,choice2;

while(1){

    while(1){

        if(num_of_students == 0){
        system("cls");
        printf("\n>> THERE ARE NO STUDENTS , press any key to back to main menu\n");
        error_sound();
        getch();
        system("cls");
        break;
    }


        system("cls");

         choice2 = print_school_scroll();

        if(choice2==1){
            sort_struct_byName(school,num_of_students);
            break;
        }
        else if(choice2==2){
            sort_struct_byAge(school,num_of_students);
            break;
        }
        else if(choice2==3){
            sort_struct_byID(school,num_of_students);
            break;
        }
        else if(choice2==4){
            sort_struct_byAraMark(school,num_of_students);
            break;
        }
        else if(choice2==5){
            sort_struct_byEngMark(school,num_of_students);
            break;
        }
        else if(choice2==6){
            break;
        }
        else{
             system("cls");
             printf("\n>> ERROR SELECTION !!!  press any key to try again\n");
            error_sound();
             getch();
             system("cls");

        }

    }

             system("cls");
    if((num_of_students == 0)||(choice2==6)){

        break;
    }

printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);

printf("%c  n  %c             Name              %c  Age  %c    phone    %c  id   %c Arabic Mark %cEnglish Mark%c\n",221,221,221,221,221,221,221,222);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223);


for(i=0;i<num_of_students;i++){

printf("%c %-4d%c ",186,i+1,186);

printf("%-30s",school[i].Name);

printf("%c  %-5d%c",186,school[i].Age,186);

printf(" %-12s%c",school[i].Phone,186);

printf(" %-6s%c",school[i].ID,186);

printf("     %-8d%c",school[i].Ara_mark,186);

printf("    %-7d",school[i].E_mark);
printf(" %c",186);

printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,188);

}


            printf("\n\n");
            printf(">> press any key to back\n");
            getch();

    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){
        system("cls");
        break;
    }



}


}
/*********************************************************************************************************************************************************************************/

// remove student

void remove_student(void){

    int i,target_index = -1;

    while(1){

    if(num_of_students == 0){
        system("cls");
        printf("\n>> THERE ARE NO STUDENTS , press any key to back to main menu\n");
        error_sound();
        getch();
        system("cls");
        break;
    }
    else{
        target_index = check_id();
    }


  while(1){

        if(num_of_students == 0){
        break;
    }

    swap_struct(&school[target_index],&school[num_of_students - 1]);
    num_of_students -- ;
    school = (student_t*)realloc(school , (num_of_students * sizeof(student_t)));
    break;

  }

      // overwrite the file with the all data after editing

    FILE *file = fopen("students.dat", "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i=0;i<num_of_students;i++) {

    fprintf(file, "%s %d %s %s %d %d\n", school[i].Name, school[i].Age , school[i].Phone, school[i].ID, school[i].Ara_mark, school[i].E_mark);

    }
    fclose(file);





    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){
        system("cls");
        break;
            }

    }

}


/*********************************************************************************************************************************************************************************/

// call student

void call_student(void){

  int target_index = -1 ,i,j;

      if(num_of_students == 0){
        system("cls");
        printf("\n>> THERE ARE NO STUDENTS , press any key to back to main menu\n");
        error_sound();
        getch();
        system("cls");
    }
    else{


      while(1){

            target_index = check_id();
            system("cls");


for(j=0;j<4;j++){



        printf("\n\t\t\t\t\t\t%s\n\n",school[target_index].Name);
        printf("\n\t\t\t\t\t\t%s\n\n",school[target_index].Phone);

printf("\t\t\t            ____    _    _     _     _ _   _       \n");
printf("\t\t\t           / ___|  / \\  | |   | |   (_) \\ | | __ _ \n");
printf("\t\t\t          | |     / _ \\ | |   | |   | |  \\| |/ _` |\n");
printf("\t\t\t          | |___ / ___ \\| |___| |___| | |\\  | (_| |\n");
printf("\t\t\t           \\____/_/   \\_\\_____|_____|_|_| \\_|\\__, |\n");
printf("\t\t\t                                             |___/ ");

        if(j==0){
             start_call_sound();

        }else{
            call_sound();
        }


for(i=0;i<4;i++){
    printf("-");
    Sleep(1000);
}
system("cls");
}


            system("cls");


printf("\t\t\t _   _  ___       _    _   _ ______        _______ ____  \n");
printf("\t\t\t| \\ | |/ _ \\     / \\  | \\ | / ___\\ \\      / / ____|  _ \\ \n");
printf("\t\t\t|  \\| | | | |   / _ \\ |  \\|  \\___ \\ \\ /\\ / /|  _| | |_) |\n");
printf("\t\t\t| |\\  | |_| |  / ___ \\| |\\  |___) |\\ V  V / | |___|  _ <\n");
printf("\t\t\t|_| \\_|\\___/  /_/   \\_\\_| \\_|____/  \\_/\\_/  |_____|_| \\_\\\n\n\n");

call_end_sound();

Sleep(2000);

    system("cls");

    int choice = YorN_scroll();

    if(choice==1 ){

        system("cls");
        continue;
    }
    else if(choice==2 ){
        system("cls");
        break;
            }



    }
}

}
