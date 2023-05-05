#pragma once
#include "Students.h"


void UpdateMark(string student_name, string subject_name, Mark old_mark, Mark new_mark) {
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
    auto it = find(marks.begin(), marks.end(), old_mark);
    if (it == marks.end()) {
        cout << "Error: mark " << old_mark << " not found for student " << student_name << " and subject " << subject_name << endl;
        return;
    }

    *it = new_mark;

    cout << "Mark " << old_mark << " updated to " << new_mark << " for student " << student_name << " and subject " << subject_name << endl;
}