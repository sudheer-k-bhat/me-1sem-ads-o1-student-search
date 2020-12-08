#ifndef STUDENT_H
#define STUDENT_H

#include <stdint.h>

typedef enum {
    PROGRAM_BDA = 10,
    PROGRAM_ML = 20,
    PROGRAM_ES = 30,
    PROGRAM_NA = 100
}Program;

typedef struct {
    char* student_name;
    float grade;
    Program program;
    float qualifying_exam_marks;
}Student;

//Linked List
typedef struct _node_ Node;
struct _node_
{
    Student* data;
    Node *next;
};

typedef struct
{
    Node *head;
    Node *tail;
    uint32_t length;
    Student* max_marks_student;
}SList;

typedef enum {
    StudentListEmpty = 10,
    StudentListOk = 20
}StudentListStatus;

typedef struct{
    StudentListStatus status;
    Student* student;
}StudentResult;

SList slist_new();

SList* slist_add_student(SList *list, Student* val, Program program);

SList* slist_search_max_marks_student(SList *list, StudentResult* result);

uint32_t slist_length(const SList *list);

#endif