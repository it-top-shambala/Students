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
void DeleteSubject(string studentName, string subject){
    _students[studentName].erase(subject);
}
void DeleteStudent(string name){
    _students.erase(name);
}
void DeleteMarkToValue(Students students, string name,string subject,int deletedMark){
    for (auto item:students) {
        for (auto item:item.second) {
            for (vector<string>::reverse_iterator i=item.second.rend(); i<item.second.rbegin(); i++) {
                if(*i==to_string(deletedMark)){
                    i->erase(1);
                    break;
                }

            }
        }
    }
}
