#include "additional_funcs.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "sounds.h"

void StrScan(char*str , int size){
    int i;
    fflush(stdin);
    for(i=0;i<(size-1);i++){

        scanf("%c",&str[i]);

        if(str[i] == '\n'){
            break;
        }

    }
    str[i]=0;     // null

}

/*****************************************************************************************************/

int StrLen(char*str){
    int i;
    for(i=0;str[i];i++);
    return i;
}

/*****************************************************************************************************/

void StrPrint(char*str){
    int i;
    for(i=0;str[i];i++){
         printf("%c",str[i]);
    }
}

/*****************************************************************************************************/

int StrCompare(char*str1 , char*str2){
    int i;

    for(i=0;(str1[i])||(str2[i]);i++){

        if(str1[i]!=str2[i]){
                return 0;
        }

    }
    return 1;

}


/*****************************************************************************************************/

int StrCompare2(char*str1 , char*str2){
    int i;

    for(i=0;(str1[i])||(str2[i]);i++){

        if(str1[i]>str2[i]){
                return 1;
        }
        else if(str1[i]<str2[i]){
                return -1;
        }

    }
    return 0;

}


/*****************************************************************************************************/

int strTOint(char*str){
    int i, number=0;


    for(i=0;str[i];i++){

            if((str[i]>='0')&&(str[i]<='9')){

        number = (10*number) +  (str[i]-'0');

            }
    }

    if(str[0]=='-'){
    return -number;
    }

    else{
    return number;
    }
}


/*****************************************************************************************************/

void StrCopy(char*str1 , char*str2){
    int i;
    for(i=0;str1[i];i++){
        str2[i]=str1[i];
    }
    str2[i]=0;

}

/*****************************************************************************************************/

void add_unique_phone_number(void){

    int i,x,phone_len,letter_found = 0;
    char phone_test[Max_string_letters];


    while(1){
        x=0;

            while(1){  // make sure that number doesn't contain letters and == 11 digit
                    letter_found = 0;
                    printf("\n  Phone Number  >>  ");          // Phone number must be UNIQUE
                    StrScan( phone_test, Max_string_letters);


                 for(i=0;i<phone_test[i];i++) { // check for letters in phone number

                    if(((phone_test[i] >= '0')&&(phone_test[i] <= '9'))||(phone_test[i]=='\0')){
                       continue;
                    }
                    else{
                        letter_found=1;
                        break;
                    }

                 }
                 if(letter_found == 0){       // no letters


                                       phone_len = StrLen(phone_test);    // make sure that phone number is 11 digit

                                       if(phone_len != 11 ){

                                                system("cls");
                                                printf("\n>> ERROR !!!  phone number must be 11 digits , press any key to try again\n");
                                                error_sound();
                                                getch();
                                                system("cls");
                                                printf("\n  Name  >>  ");
                                                StrPrint(school[num_of_students-1].Name);
                                                printf("\n");
                                                printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                                                printf("\n");
                                       }
                                       else{
                                        break;
                                       }

                 }

                else{
                    system("cls");
                    printf("\n>> ERROR !!!  phone number contains (non-number) characters , press any key to try again\n");
                             error_sound();
                    getch();
                    system("cls");
                    printf("\n  Name  >>  ");
                    StrPrint(school[num_of_students-1].Name);
                    printf("\n");
                    printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                    printf("\n");
                }
            }




            for(i=0;i<num_of_students;i++){     // check for phone

                x=StrCompare(phone_test , school[i].Phone);

                if(x==1){    // phone is found
                    system("cls");
                    printf("\n>> SORRY !!! THIS PHONE NUMBER WAS ADDED BEFORE , ");
                    printf("press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                    break;
                }
            }

            if(x==0){ // not found before
                StrCopy(phone_test , school[num_of_students - 1].Phone);
                break;
            }
            else{

                printf("\n  Name  >>  ");
                StrPrint(school[num_of_students-1].Name);
                printf("\n");

                printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                printf("\n");

            }

    }

}

/*****************************************************************************************************/

void add_unique_id(void){

    int i,x,letter_found=0,id_len;
    char id_test[Max_string_letters];



    while(1){
        x=0;

            while(1){  // make sure that ID doesn't contain letters and == 5 digit
                    letter_found = 0;
                    printf("\n  ID  >>  ");          // ID must be UNIQUE
                    StrScan( id_test, Max_string_letters);


                 for(i=0;i<id_test[i];i++) { // check for letters in id

                    if(((id_test[i] >= '0')&&(id_test[i] <= '9'))||(id_test[i]=='\0')){
                       continue;
                    }
                    else{
                        letter_found=1;
                        break;
                    }

                 }
                 if(letter_found == 0){       // no letters


                                       id_len = StrLen(id_test);    // make sure that id is not > 5 digit

                                       if(id_len > 5 ){

                                                system("cls");
                                                printf("\n>> ERROR !!!  id must be <= 5 digits , press any key to try again\n");
                                                         error_sound();
                                                getch();
                                                system("cls");
                                                printf("\n  Name  >>  ");
                                                StrPrint(school[num_of_students-1].Name);
                                                printf("\n");
                                                printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                                                printf("\n");
                                                printf("\n  Phone Number  >>  ");
                                                StrPrint(school[num_of_students-1].Phone);
                                                printf("\n");

                                       }
                                       else{
                                        break;
                                       }

                 }

                else{
                    system("cls");
                    printf("\n>> ERROR !!!  ID contains (non-number) characters , press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                    printf("\n  Name  >>  ");
                    StrPrint(school[num_of_students-1].Name);
                    printf("\n");
                    printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                    printf("\n");
                    printf("\n  Phone Number  >>  ");
                    StrPrint(school[num_of_students-1].Phone);
                    printf("\n");
                }
            }




            for(i=0;i<num_of_students;i++){     // check for ID

                x=StrCompare(id_test , school[i].ID);

                if(x==1){    // ID is found
                    system("cls");
                    printf("\n>> SORRY !!! THIS ID WAS ADDED BEFORE , ");
                    printf("press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                    break;
                }
            }

            if(x==0){ // not found before
                StrCopy(id_test , school[num_of_students - 1].ID);
                break;
            }
            else{

                printf("\n  Name  >>  ");
                StrPrint(school[num_of_students-1].Name);
                printf("\n");

                printf("\n  Age  >>  %d",school[num_of_students-1].Age);
                printf("\n");

                printf("\n  Phone Number  >>  ");
                StrPrint(school[num_of_students-1].Phone);
                printf("\n");


            }

    }

}

/*****************************************************************************************************/

void edit_phone_number(int target_index){


    int i,x,phone_len,letter_found = 0;
    char phone_test[Max_string_letters];


    while(1){
        x=0;

            while(1){  // make sure that number doesn't contain letters and == 11 digit
                    letter_found = 0;
                    printf("\n  New Phone Number  >>  ");          // Phone number must be UNIQUE
                    StrScan( phone_test, Max_string_letters);


                 for(i=0;i<phone_test[i];i++) { // check for letters in phone number

                    if(((phone_test[i] >= '0')&&(phone_test[i] <= '9'))||(phone_test[i]=='\0')){
                       continue;
                    }
                    else{
                        letter_found=1;
                        break;
                    }

                 }
                 if(letter_found == 0){       // no letters

                                       phone_len = StrLen(phone_test);    // make sure that phone number is 11 digit

                                       if(phone_len != 11 ){

                                                system("cls");
                                                printf("\n>> ERROR !!!  phone number must be 11 digits , press any key to try again\n");
                                                         error_sound();

                                                getch();
                                                system("cls");

                                       }
                                       else{
                                        break;
                                       }

                 }

                else{
                    system("cls");
                    printf("\n>> ERROR !!!  phone number contains (non-number) characters , press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                }
            }
// new phone num is 11 digit and without non-numbers , now check for repeat


            for(i=0;i<num_of_students;i++){     // check for phone num

                x=StrCompare(phone_test , school[i].Phone);

                if(x==1){    // phone is found
                    system("cls");
                    printf("\n>> SORRY !!! THIS PHONE NUMBER WAS ADDED BEFORE , ");
                    printf("press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                    break;
                }
            }

            if(x==0){ // not found before
                StrCopy(phone_test , school[target_index].Phone);
                break;
            }


    }

}


/*****************************************************************************************************/

void edit_id(int target_index){



    int i,x,letter_found=0,id_len;
    char id_test[Max_string_letters];



    while(1){
        x=0;

            while(1){  // make sure that ID doesn't contain letters and == 5 digit
                    letter_found = 0;
                    printf("\n  New ID  >>  ");          // ID must be UNIQUE
                    StrScan( id_test, Max_string_letters);


                 for(i=0;i<id_test[i];i++) { // check for letters in id

                    if(((id_test[i] >= '0')&&(id_test[i] <= '9'))||(id_test[i]=='\0')){
                       continue;
                    }
                    else{
                        letter_found=1;
                        break;
                    }

                 }
                 if(letter_found == 0){       // no letters


                                       id_len = StrLen(id_test);    // make sure that id is not > 5 digit

                                       if(id_len > 5 ){

                                                system("cls");
                                                printf("\n>> ERROR !!!  id must be <= 5 digits , press any key to try again\n");
                                                         error_sound();

                                                getch();
                                                system("cls");
                                       }
                                       else{
                                        break;
                                       }

                 }

                else{
                    system("cls");
                    printf("\n>> ERROR !!!  ID contains (non-number) characters , press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                }
            }




            for(i=0;i<num_of_students;i++){     // check for ID

                x=StrCompare(id_test , school[i].ID);

                if(x==1){    // ID is found
                    system("cls");
                    printf("\n>> SORRY !!! THIS ID WAS ADDED BEFORE , ");
                    printf("press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                    break;
                }
            }

            if(x==0){ // not found before
                StrCopy(id_test , school[target_index].ID);
                break;
            }


    }


}

/*****************************************************************************************************/

int check_id(void){

    int i,x,target_index=-1,letter_found=0,id_len;
    char id_edit[Max_string_letters];

    while(target_index == -1){


                while(1){                 // make sure that ID doesn't contain letters and == 5 digit
                    letter_found = 0;
                    printf("\n  ID  >>  ");          // ID must be UNIQUE
                    StrScan( id_edit, Max_string_letters);


                 for(i=0;i<id_edit[i];i++) { // check for letters in id

                    if(((id_edit[i] >= '0')&&(id_edit[i] <= '9'))||(id_edit[i]=='\0')){
                       continue;
                    }
                    else{
                        letter_found=1;
                        break;
                    }

                 }
                 if(letter_found == 0){       // no letters


                                       id_len = StrLen(id_edit);    // make sure that id is not > 5 digit

                                       if(id_len > 5 ){

                                                system("cls");
                                                printf("\n>> ERROR !!!  id must be <= 5 digits , press any key to try again\n");
                                                         error_sound();

                                                getch();
                                                system("cls");

                                       }
                                       else{
                                        break;
                                       }

                 }

                else{
                    system("cls");
                    printf("\n>> ERROR !!!  ID contains (non-number) characters , press any key to try again\n");
                             error_sound();

                    getch();
                    system("cls");
                }
            }  // don't get out from here untill writing valid id


    for(i=0;i<num_of_students;i++){     // search for id

        x=StrCompare(id_edit , school[i].ID);

        if(x==1){    // id is found
            target_index = i;
            break;
        }

    }

    if(target_index==-1){  // not found
                system("cls");
                printf("\n>> WRONG ID !!!  press any key to try again\n");
                         error_sound();

                getch();
                system("cls");
    }

    }

    // won't get out from here untill right id is entered

    return target_index;
}

/*****************************************************************************************************/

void add_age(void){
    int age_check;

    while(1){


    printf("\n  Age   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&age_check);

    if((age_check>=7)&&(age_check<=18)){
            school[num_of_students - 1].Age = age_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 7<= Age <=18 ) , press any key to try again");
                 error_sound();

        getch();
        system("cls");
        printf("\n  Name  >>  ");
        StrPrint(school[num_of_students-1].Name);
        printf("\n");

    }

    }

}

/*****************************************************************************************************/

void add_name(void){

    char name_check[Max_string_letters];
    int i,name_len,num_found=0;

    while(1){
            num_found=0;
    printf("\n  Name  >>  ");              // not unique
    StrScan( name_check, Max_string_letters);
    name_len = StrLen(name_check);

    if(name_len<Max_Name_letters){       // name length is right

                for(i=0;name_check[i];i++) { // check for (non-alphabet) in name

                    if(((name_check[i] >= 'A')&&(name_check[i] <= 'Z'))||((name_check[i] >= 'a')&&(name_check[i] <= 'z'))||(name_check[i]=='\0')||(name_check[i]==' ')){
                       continue;
                    }
                    else{
                        num_found=1;
                        break;
                    }

                 }

                 if(num_found==0){       // name without (non-alphabet)
                        StrCopy(name_check,school[num_of_students - 1].Name);
                        break;
                 }
                 else{
                    system("cls");
                    printf("\n>> Error!!! Name should contain only alphabets");
                             error_sound();

                    getch();
                    system("cls");
                    }


    }
    else{
        system("cls");
        printf("\n>> Error!!! Name should be <= 30 letters , press any key to try again");
                 error_sound();

        getch();
        system("cls");
    }
    }
}

/*****************************************************************************************************/

void add_arabic_mark(void){
    int ara_check;

    while(1){


    printf("\n  Arabic Mark   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&ara_check);

    if((ara_check>=0)&&(ara_check<=100)){
            school[num_of_students - 1].Ara_mark = ara_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 0<= arabic mark <=100 ) , press any key to try again");
                 error_sound();
        getch();
        system("cls");
        printf("\n  Name  >>  ");
        StrPrint(school[num_of_students-1].Name);
        printf("\n");
        printf("Age  >>  %d",school[num_of_students-1].Age);
        printf("\n");
        printf("Phone Number  >>  ");
        StrPrint(school[num_of_students-1].Phone);
        printf("\n");
        printf("ID  >>  ");
        StrPrint(school[num_of_students-1].ID);
        printf("\n");
    }

    }

}


/*****************************************************************************************************/

void add_english_mark(void){
    int eng_check;

    while(1){


    printf("\n  English Mark   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&eng_check);

    if((eng_check>=0)&&(eng_check<=100)){
            school[num_of_students - 1].E_mark = eng_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 0<= english mark <=100 ) , press any key to try again");
                 error_sound();
        getch();
        system("cls");
        printf("\n  Name  >>  ");
        StrPrint(school[num_of_students-1].Name);
        printf("\n");
        printf("\n  Age  >>  %d",school[num_of_students-1].Age);
        printf("\n");
        printf("\n  Phone Number  >>  ");
        StrPrint(school[num_of_students-1].Phone);
        printf("\n");
        printf("\n ID  >>  ");
        StrPrint(school[num_of_students-1].ID);
        printf("\n");
        printf("\n  Arabic Mark  >>  %d",school[num_of_students-1].Ara_mark);
        printf("\n");
    }

    }

}

/*****************************************************************************************************/
void name_edit(int target_index){

char name_check[Max_string_letters];
    int i,name_len,num_found=0;

    while(1){
            num_found=0;
    printf("\n  New Name  >>  ");              // not unique
    StrScan( name_check, Max_string_letters);
    name_len = StrLen(name_check);

    if(name_len<Max_Name_letters){       // name length is right

                for(i=0;name_check[i];i++) { // check for (non-alphabet) in name

                    if(((name_check[i] >= 'A')&&(name_check[i] <= 'Z'))||((name_check[i] >= 'a')&&(name_check[i] <= 'z'))||(name_check[i]=='\0')||(name_check[i]==' ')){
                       continue;
                    }
                    else{
                        num_found=1;
                        break;
                    }

                 }

                 if(num_found==0){       // name without (non-alphabet)
                        StrCopy(name_check,school[target_index].Name);
                        break;
                 }
                 else{
                    system("cls");
                    printf("\n>> Error!!! Name should contain only alphabets");
                             error_sound();

                    getch();
                    system("cls");
                    }


    }
    else{
        system("cls");
        printf("\n>> Error!!! Name should be <= 30 letters , press any key to try again");
                 error_sound();
        getch();
        system("cls");
    }
    }

}

/*****************************************************************************************************/

void age_edit(int target_index){

    int age_check;

    while(1){


    printf("\n  New Age   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&age_check);

    if((age_check>=7)&&(age_check<=18)){
            school[target_index].Age = age_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 7<= Age <=18 ) , press any key to try again");
                 error_sound();

        getch();
        system("cls");

    }

    }

}


/*****************************************************************************************************/

void ara_edit(int target_index){


    int ara_check;

    while(1){


    printf("\n  New Arabic Mark   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&ara_check);

    if((ara_check>=0)&&(ara_check<=100)){
            school[target_index].Ara_mark = ara_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 0<= arabic mark <=100 ) , press any key to try again");
                 error_sound();

        getch();
        system("cls");
    }

    }

}

/*****************************************************************************************************/

void eng_edit(int target_index){


    int eng_check;

    while(1){


    printf("\n  New English Mark   >>  ");                              // not unique
    fflush(stdin);
    scanf("%d",&eng_check);

    if((eng_check>=0)&&(eng_check<=100)){
            school[target_index].E_mark = eng_check;
            break;
    }
    else{
        system("cls");
        printf("\n>> Error !!! ( 0<= english mark <=100 ) , press any key to try again");
                 error_sound();

        getch();
        system("cls");
    }

    }

}

/*****************************************************************************************************/

void swap_struct(student_t * s1 , student_t * s2){

    student_t temp;

    temp = *s1;
    *s1=*s2;
    *s2 = temp;

}

/*****************************************************************************************************/

void sort_struct_byID(student_t * arr , int size){
    int i,j,max_index;

    for(i=0;i<size;i++){
        max_index=0;
        for(j=0;j<size-i;j++){     // max id

            if((strTOint(arr[j].ID)) > (strTOint(arr[max_index].ID))){ // max =<
                max_index = j;
            }
        }

        swap_struct(&arr[max_index],&arr[size-i-1]);

    }

}



/*****************************************************************************************************/

void sort_struct_byAge(student_t * arr , int size){

    int i,j,max_index;

    for(i=0;i<size;i++){

        sort_struct_byID(school,size-i);  // we will sort them by ID at first after each swap (except the max), because if two students have same any data , they will be sorted bi ID
        max_index=0;

        for(j=0;j<size-i;j++){     // max  Age

            if(arr[j].Age  >=  arr[max_index].Age){ // max =<
                max_index = j;
            }
        }

        swap_struct(&arr[max_index],&arr[size-i-1]);

    }

}


/*****************************************************************************************************/

void sort_struct_byName(student_t * arr , int size){
    int i,j,x,max_index;

    for(i=0;i<size;i++){

        sort_struct_byID(school,size-i);  // we will sort them by ID at first after each swap (except the max), because if two students have same any data , they will be sorted bi ID
        max_index=0;


        for(j=0;j<size-i;j++){     // max name

            x=StrCompare2(arr[max_index].Name,arr[j].Name);

            if((x==-1)||(x==0)){ // max =<
                max_index = j;
            }
        }

        swap_struct(&arr[max_index],&arr[size-i-1]);

    }

}

/*****************************************************************************************************/



void sort_struct_byAraMark(student_t * arr , int size){

    int i,j,min_index;

    for(i=0;i<size;i++){

        sort_struct_byID(school,size-i);  // we will sort them by ID at first after each swap (except the max), because if two students have same any data , they will be sorted bi ID
        min_index=0;


        for(j=0;j<size-i;j++){     // max Arabic Mark

            if(arr[j].Ara_mark  <=  arr[min_index].Ara_mark){ // max =<
                min_index = j;
            }
        }

        swap_struct(&arr[min_index],&arr[size-i-1]);

    }

}


/*****************************************************************************************************/

void sort_struct_byEngMark(student_t * arr , int size){

    int i,j,min_index;

    for(i=0;i<size;i++){




        sort_struct_byID(school,size-i);  // we will sort them by ID at first after each swap (except the max), because if two students have same any data , they will be sorted bi ID
        min_index=0;






        for(j=0;j<num_of_students-i;j++){     // max English Mark

            if(arr[j].E_mark  <=  arr[min_index].E_mark){ // max =<
                min_index = j;
            }
        }

        swap_struct(&arr[min_index],&arr[size-i-1]);

    }

}

/*****************************************************************************************************/


