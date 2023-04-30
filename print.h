#pragma once
#include "mark.h"
#include "subject.h"
#include "student.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;


void PrintMark(Mark mark) {
    cout << mark.value << ", ";
}

void PrintMarks(vector<Mark> marks) {
    for (const auto& mark : marks) {
        PrintMark(mark);
    }
    cout << endl;
}

void PrintSubject(Subject subject) {
    cout << subject.name << ": ";
    PrintMarks(subject.marks);
}

void PrintSubjects(map<string, Subject> subjects) {
    for (const auto& [name, subject] : subjects) {
        PrintSubject(subject);
    }
}

void PrintStudent(Student student) {
    cout << student.name << ":" << endl;
    PrintSubjects(student.subjects);
}

void PrintStudents() {
    for (const auto& [name, student] : students) {
        PrintStudent(student);
    }
}
