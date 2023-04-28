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
    auto mark_it = remove(marks.begin(), marks.end(), mark);
    marks.erase(mark_it, marks.end());
//    marks.erase(remove(marks.begin(), marks.end(), mark), marks.end());
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

void ExportData(string filename) {
    ofstream outfile(filename);
    for (auto& student : _students) {
        outfile << student.first << endl;
        for (auto& subject : student.second) {
            outfile << subject.first << endl;
            for (auto& mark : subject.second) {
                outfile << mark << ",";
            }
            outfile << endl;
        }
        outfile << endl;
    }
    outfile.close();
    cout << "Данные экспортированы в файл " << filename << endl;
}

void ImportData(string filename) {
    ifstream infile(filename);
    string line;
    string student_name;
    string subject_name;
    Mark mark;

    while (getline(infile, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.back() == ':') {
            student_name = line.substr(0, line.size() - 1);
            InsertStudent(student_name);
        } else if (isalpha(line[0])) {
            subject_name = line;
            InsertSubject(student_name, subject_name);
        } else {
            stringstream ss(line);
            while (getline(ss, mark, ',')) {
                InsertMark(student_name, subject_name, mark);
            }
        }
    }
    infile.close();
    cout << "Данные импортированы из файла " << filename << endl;
}