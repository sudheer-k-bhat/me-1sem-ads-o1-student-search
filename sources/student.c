#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "student.h"

SList slist_new()
{
    SList slist = {NULL, NULL, 0, NULL};
    return slist;
}

uint32_t slist_length(const SList *list)
{
    assert(list != NULL);
    return list->length;
}

static Node *_get_new_node(Student *student, Program program)
{
    student->program = program;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = student;
    node->next = NULL;
    return node;
}

SList *slist_add_student(SList *list, Student *student, Program program)
{
    assert(list != NULL);
    Node *node = _get_new_node(student, program);
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->length += 1;

    //Keeping max marks student as a member in SList to achieve O(1) time.
    if (list->max_marks_student == NULL || student->qualifying_exam_marks > list->max_marks_student->qualifying_exam_marks)
    {
        list->max_marks_student = student;
    }
    return list;
}

SList *slist_search_max_marks_student(SList *list, StudentResult *result)
{
    assert(list != NULL);
    if (list->length == 0)
    {
        result->status = StudentListEmpty;
    }
    else
    {
        result->status = StudentListOk;
        result->student = list->max_marks_student;
    }
    return list;
}