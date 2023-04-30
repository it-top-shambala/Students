#pragma once
#include <string>
#include <vector>
#include <map>
#include "student.h"


void DeleteMark(string student_name, string subject_name, int mark_index) {
    students[student_name].subjects[subject_name].marks.erase(students[student_name].subjects[subject_name].marks.begin() + mark_index);
}

void DeleteSubject(string student_name, string subject_name) {
    students[student_name].subjects.erase(subject_name);
}

void DeleteStudent(string student_name) {
    students.erase(student_name);
}