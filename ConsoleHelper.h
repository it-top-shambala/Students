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
}

void PrintStudent(Student student) {
    cout << student.first << ":" << endl;
    PrintSubjects(student.second);
}

void PrintStudents(Students students) {
    for (Student student : _students) {
        PrintStudent(student);
    }
}
void ShowStudents(Students students){
    for (auto item:students) {
        cout<<item.first<<" ";
        for (auto item:item.second) {
            cout<<item.first<<":";
            for (auto item:item.second ) {
                cout<<item<<" ";
            }
        }
        cout<<endl;
    }
}