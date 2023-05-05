#pragma once

#include <string>
#include <vector>
#include <map>
#include "Students.h"

//Load (import) function from a file
void LoadDataFromFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string student_name, subject_name, mark_str;
        Marks marks;

        istringstream iss(line);
        iss >> student_name >> subject_name;

        while (iss >> mark_str) {
            marks.push_back(mark_str);
        }

        if (_students.find(student_name) == _students.end()) {
            InsertStudent(student_name);
        }

        if (_students[student_name].find(subject_name) == _students[student_name].end()) {
            InsertSubject(student_name, subject_name);
        }

        InsertMarks(student_name, subject_name, marks);
    }

    file.close();
}
//The function of exporting to a file from a file
void ExportDataToFile(string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }

    for (const auto& student : _students) {
        file << student.first << ":" << endl;
        for (const auto& subject : student.second) {
            file << subject.first << " ";

            for (const auto& mark : subject.second) {
                file << mark << " ";
            }

            file << endl;
        }
    }

    file.close();
}
//Student removal function
void RemoveStudent(string student_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    _students.erase(student_name);

    cout << "Student " << student_name << " removed from the list" << endl;
}
//The function of removing the subject from the student
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
//The function of removing a student's grade in a subject
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
//The function of updating the student's pridmet score
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
