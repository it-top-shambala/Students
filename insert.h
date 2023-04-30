#pragma once
#include <string>
#include <vector>
#include <map>
#include "student.h"
#include "mark.h"


void InsertStudent(string name) {
    Student student;
    student.name = name;
    students.insert({ name, student });
}

void InsertSubject(string student_name, string subject_name) {
    Subject subject;
    subject.name = subject_name;
    students[student_name].subjects.insert({ subject_name, subject });
}

void InsertMark(string student_name, string subject_name, Mark mark) {
    students[student_name].subjects[subject_name].marks.push_back(mark);
}

void InsertMarks(string student_name, string subject_name, vector<Mark> marks) {
    for (const auto& mark : marks) {
        students[student_name].subjects[subject_name].marks.push_back(mark);
    }
}