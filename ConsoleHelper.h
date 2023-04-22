#pragma once

#include <iostream>

#include "Students.h"

void PrintMark(Mark mark) {
    cout << mark << ", ";
}

void PrintMarks(Marks marks) {
    for (Mark mark : marks) {
        PrintMark(mark);
    }
    cout << endl;
}

void PrintSubject(Subject subject) {
    cout << subject.first << ": ";
    PrintMarks(subject.second);
}

void PrintSubjects(Subjects subjects) {
    for (Subject subject : subjects) {
        PrintSubject(subject);
    }
    cout << endl;
}

void PrintStudent(Student student) {
    cout << student.first << ":" << endl;
    PrintSubjects(student.second);
}

void PrintStudents() {
    for (Student student : _students) {
        PrintStudent(student);
    }
    cout << "--------------" << endl;
}