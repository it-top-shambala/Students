/*
 * Студент 1:
 *      Предмет 1: 5,5,4,1
 *      Предмет 2: 5,5,4,1
 *      Предмет 3: 5,5,4,1
* Студент 2:
 *      Предмет 1: 5,5,4,1
 *      Предмет 6: 5,5,4,1
 *      Предмет 3: 5,5,4,1
 */

#pragma once

#include <string>
#include <vector>
#include <map>


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
void InsertSubject(string student_name, string subject_name) {
    Marks temp;
    _students[student_name].insert(Subject(subject_name, temp));
}
void InsertMark(string student_name, string subject_name, Mark mark) {
    _students[student_name][subject_name].push_back(mark);
}
void InsertMarks(string student_name, string subject_name, Marks marks) {
    for (Mark mark : marks) {
        _students[student_name][subject_name].push_back(mark);
    }
}
void DeleteMark(string student_name, string subject_name, int index){
    if (index >= 0 && index <  _students[student_name][subject_name].size()){
        _students[student_name][subject_name].erase(_students[student_name][subject_name].begin() + index);
    } else {
        cerr << "Invalid index" << endl;
    }
}
void DeleteSubject(string student_name, string subject_name) {
    auto item1 = _students.find(student_name);
            if (item1 != _students.end()){
                auto item2 = _students[student_name].find(subject_name);
                if (item2 != _students[student_name].end()){
                    _students[student_name].erase(subject_name);
                }
            }
            else cerr << "Invalid NAME or SUBJECT" << endl;
}
void DeleteStudent(string name) {
    auto item = _students.find(name);
    if (item != _students.end()) {
        _students.erase(name);
    } else {
        cerr << "Invalid NAME!" << endl;
    }

}
void UpdateMark(string student_name, string subject_name, int index, string new_mark){
    if (index >= 0 && index <  _students[student_name][subject_name].size()){
        _students[student_name][subject_name][index] = new_mark;
    } else {
        cerr << "Invalid index" << endl;
    }
}