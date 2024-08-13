#include <stdio.h>
#include <stdlib.h>
#define Max_Name_letters   31
#define Max_string_letters   32        // to check if > 30
#define Max_Phone_Number_digits   12
#define Max_ID_digits   6

/***********************************************************************/
extern int num_of_students;   // global
/***********************************************************************/

typedef struct student {
    char Name[Max_Name_letters];    // 1 for null
    int Age;
    char Phone[Max_Phone_Number_digits];   // 1 for null
    char ID[Max_ID_digits];       // 1 for null
    int Ara_mark;
    int E_mark;
}student_t;

/***********************************************************************/
extern student_t* school;     // global  (reserve for one student)
/***********************************************************************/
void add_student(void);
void edit_student(void);
void student_print(void);
void school_print(void);
void remove_student(void);
void call_student(void);
/***********************************************************************/

