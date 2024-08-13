#include <stdio.h>
#include <stdlib.h>
#include "features.h"



void StrScan(char*str , int MaxSize);
void StrPrint(char*str);
int StrCompare(char*str1 , char*str2);
int StrCompare2(char*str1 , char*str2);
int strTOint(char*str);
void StrCopy(char*str1 , char*str2);

void add_name(void);
void add_age(void);
void add_unique_phone_number(void);
void add_unique_id(void);
void add_arabic_mark(void);
void add_english_mark(void);

int check_id(void);

void name_edit(int target_index);
void age_edit(int target_index);
void edit_phone_number(int target_index);
void edit_id(int target_index);
void ara_edit(int target_index);
void eng_edit(int target_index);

void swap_struct(student_t * s1 , student_t * s2);
void sort_struct_byAge(student_t * arr , int size);
void sort_struct_byName(student_t * arr , int size);
void sort_struct_byID(student_t * arr , int size);
void sort_struct_byAraMark(student_t * arr , int size);
void sort_struct_byEngMark(student_t * arr , int size);

