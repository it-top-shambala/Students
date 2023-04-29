#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

using Mark = string;
using Marks = vector<Mark>;

using Subjects = map<string, Marks>;
using Subject = pair<string, Marks>;

using Students = map<string, Subjects>;
using Student = pair<string, Subjects>;

Students _students;

void InsertStudent(string name) {
    Subjects temp;
    _students.insert(Student(name, temp));
}

void RemoveStudent(string name) {
    _students.erase(name);
}

void InsertSubject(string student_name, string subject_name) {
    Marks temp;
    _students[student_name].insert(Subject(subject_name, temp));
}

void RemoveSubject(string student_name, string subject_name) {
    _students[student_name].erase(subject_name);
}

void InsertMark(string student_name, string subject_name, Mark mark) {
    _students[student_name][subject_name].push_back(mark);
}

void RemoveMark(string student_name, string subject_name, Mark mark) {
    auto& marks = _students[student_name][subject_name];
    marks.erase(remove(marks.begin(), marks.end(), mark), marks.end());
}

void InsertMarks(string student_name, string subject_name, Marks marks) {
    for (Mark mark : marks) {
        _students[student_name][subject_name].push_back(mark);
    }
}

void UpdateMark(string student_name, string subject_name, Mark old_mark, Mark new_mark) {
    auto& marks = _students[student_name][subject_name];
    replace(marks.begin(), marks.end(), old_mark, new_mark);
}

