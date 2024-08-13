#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "features.h"





// load data


void load_students(void){
    FILE *file = fopen("students.dat", "r");

    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }

    char line[100];  // Assuming a maximum line length of 100 characters

    school = realloc(school, (num_of_students + 1) * sizeof(student_t));

    while (fgets(line, sizeof(line), file) != NULL) {
        int result = sscanf(line, "%[^0-9] %d %s %s %d %d",
                            school[num_of_students].Name,
                            &school[num_of_students].Age,
                            school[num_of_students].Phone,
                            school[num_of_students].ID,
                            &school[num_of_students].Ara_mark,
                            &school[num_of_students].E_mark);

        if (result == 6) {
            num_of_students++;
            school = realloc(school, (num_of_students + 1) * sizeof(student_t));
        }
    }

    school = realloc(school, num_of_students * sizeof(student_t));

    fclose(file);
}





// load data from file (this func will cause problems when name contains more than 1 word with space between)

/*
void load_students(void){

    FILE *file = fopen("students.dat", "r");

    if (file == NULL) {
        printf("No existing data found.\n");
        return;
    }
        school = realloc(school, (num_of_students + 1) * sizeof(student_t));  // reserve struct student in heap at first to enable us to put the first student then continue in loop

    while (fscanf(file, "%s %d %s %s %d %d", school[num_of_students].Name,
                  &school[num_of_students].Age , school[num_of_students].Phone,
                  school[num_of_students].ID, &school[num_of_students].Ara_mark,
                  &school[num_of_students].E_mark) == 6) {
        num_of_students++;
        school = realloc(school, (num_of_students + 1) * sizeof(student_t));
    }
        school = realloc(school, (num_of_students ) * sizeof(student_t));  // after loop , num_of_students is right , but we reserve an addition struct student so modify that


    fclose(file);
}
*/

