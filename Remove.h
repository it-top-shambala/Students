#pragma once

#include "Students.h"
void RemoveStudent(string student_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    _students.erase(student_name);

    cout << "Student " << student_name << " removed from the list" << endl;
}
void RemoveSubject(string student_name, string subject_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    auto& subjects = _students[student_name];
    if (subjects.find(subject_name) == subjects.end()) {
        cout << "Error: subject " << subject_name << " not found for student " << student_name << endl;
        return;
    }

    subjects.erase(subject_name);

    cout << "Subject " << subject_name << " removed from student " << student_name << endl;
}
void RemoveMark(string student_name, string subject_name, Mark mark) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    auto& subjects = _students[student_name];
    if (subjects.find(subject_name) == subjects.end()) {
        cout << "Error: subject " << subject_name << " not found for student " << student_name << endl;
        return;
    }

    auto& marks = subjects[subject_name];
    auto it = find(marks.begin(), marks.end(), mark);
    if (it == marks.end()) {
        cout << "Error: mark " << mark << " not found for student " << student_name << " and subject " << subject_name << endl;
        return;
    }

    marks.erase(it);

    cout << "Mark " << mark << " removed from student " << student_name << " and subject " << subject_name << endl;
}