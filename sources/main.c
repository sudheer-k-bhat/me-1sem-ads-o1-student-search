#include <assert.h>
#include <stdio.h>

#include "student.h"

void test_slist_new(){
    SList lst = slist_new();
    SList* list = &lst;
    assert(slist_length(list) == 0);
}

void test_add_student(){
    SList lst = slist_new();
    SList* list = &lst;
    Student std1 = {"Sudheer Keshav Bhat", 7.8, PROGRAM_NA, 88};
    Student* student1 = &std1;
    slist_add_student(list, student1, PROGRAM_BDA);
    assert(slist_length(list) == 1);
    Student std2 = {"Sridevi H", 7.9, PROGRAM_NA, 92};
    Student* student2 = &std2;
    slist_add_student(list, student2, PROGRAM_ML);
    assert(slist_length(list) == 2);
}

//This won't work unless you copy the string & structure before using it,
SList* _add_student(SList* list, char* name, float grade, Program program, float marks){
    Student std = {name, grade, PROGRAM_NA, marks};
    Student* student = &std;
    return slist_add_student(list, student, program);
}

void test_search_max_marks_student(){
    SList lst = slist_new();
    SList* list = &lst;
    StudentResult result;
    slist_search_max_marks_student(list, &result);

    assert(result.status == StudentListEmpty);
    Student std1 = {"Sudheer Keshav Bhat", 7.8, PROGRAM_NA, 88};
    Student* student1 = &std1;
    slist_add_student(list, student1, PROGRAM_BDA);

    Student std2 = {"Sridevi H", 7.9, PROGRAM_NA, 92};
    Student* student2 = &std2;
    list = slist_add_student(list, student2, PROGRAM_ML);
    Student std3 = {"Vittal Hari", 8.1, PROGRAM_NA, 89};
    Student* student3 = &std3;
    list = slist_add_student(list, student3, PROGRAM_ML);
    list = slist_search_max_marks_student(list, &result);
    assert(result.status == StudentListOk && result.student->qualifying_exam_marks == 92);
}

int main(){
    test_slist_new();
    test_add_student();
    test_search_max_marks_student();
    return 0;
}