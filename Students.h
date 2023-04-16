#pragma once

#include "IncludingLibraries.h"
#include "AliasesOfTypes.h"

Students _students;

void InsertStudent(const string name) {
    _students.insert(Student(name, {}));
    //_students.insert(pair<string, map<string, vector<string>>>(name, {}));
}

void ParsingEnteredStudentsName(string studentsName)
{
    string name = "";
    for (int i = 0; i < studentsName.size();) {
        if (studentsName[i] != ',') {
            name += studentsName[i];
            ++i;
        } else {
            InsertStudent(name);
            name = "";
            ++i;
        }
    }
    InsertStudent(name);
}

void InsertSubject(string student_name, string subject_name) {
    _students[student_name].insert(Subject(subject_name, {}));
    //_students[student_name].insert(pair<string, vector<string>>(subject_name, {}))
}

void ParsingEnteredStudentsSubjects(string subjectsNames)
{
    string subjectName = "";
    vector<string> subjects;
    for (int i = 0; i < subjectsNames.size();) {
        if (subjectsNames[i] != ',') {
            subjectName += subjectsNames[i];
            ++i;
        } else {
            subjects.push_back(subjectName);
            subjectName = "";
            ++i;
        }
    }
    subjects.push_back(subjectName);

    for (int i = 0; i < subjects.size(); ++i)
    {
        map<string, map<string, vector<string>>>::iterator it_student;
        for (it_student = _students.begin(); it_student != _students.end(); ++it_student)
        {

            InsertSubject( (*it_student).first, subjects[i]);
        }
    }
}


void InsertMark(string student_name, string subject_name, Mark mark) {
    _students[student_name][subject_name].push_back(mark);
}

void InsertMarks(string student_name, string subject_name, Marks marks) {
    for (Mark mark: marks) {
        _students[student_name][subject_name].push_back(mark);
    }
}

void UpdateMark(string student_name, string subject_name, Mark oldmark, Mark newMark) {
    for (const auto &student: _students) {
        if (student.first == student_name) {
            for (const auto &subject: student.second) {
                if (subject.first == subject_name) {
                    vector<string> &marks = _students[student_name][subject_name];
                    vector<string>::iterator it;
                    for (it = marks.begin(); it < marks.end(); ++it) {
                        if ((*it) == oldmark) {
                            (*it) = newMark;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void UpdateMarkPosition(vector<string> nameStudent, string nameSubject, string position, string mark) {
    int pos = stoi(position);
    for (int i = 0; i < nameStudent.size(); ++i) {
        if (pos > 0 && pos <= (_students[nameStudent[i]][nameSubject]).size()) {
            (_students[nameStudent[i]][nameSubject])[pos-1] = mark;
        }

    }
}

void UpdateMark(vector<string> nameStudent, string nameSubject, string mark) {
    for (int i = 0; i < nameStudent.size(); ++i) {
            (_students[nameStudent[i]][nameSubject]).push_back(mark);
    }
}

void DeleteStudent(vector<string> nameStudent) {
    for (int i = 0; i < nameStudent.size(); ++i) {
        _students.erase(nameStudent[i]);
    }
}

void DeleteSubject(string nameSubject) {
    map<string, map<string, vector<string>>>::iterator it_student;
    for (it_student = _students.begin(); it_student != _students.end(); ++it_student)
    {

         (*it_student).second.erase(nameSubject);
    }
}

void DeleteSubject(vector<string> nameStudent, string nameSubject) {
    for (int i = 0; i < nameStudent.size(); ++i) {
        _students[nameStudent[i]].erase(nameSubject);
    }
}

void DeleteMarks(vector<string> nameStudent, string nameSubject) {
    for (int i = 0; i < nameStudent.size(); ++i) {
        _students[nameStudent[i]][nameSubject].erase(_students[nameStudent[i]][nameSubject].cbegin(),
                                                     _students[nameStudent[i]][nameSubject].end());
    }
}

void DeleteMark(vector<string> nameStudent, string nameSubject, string mark) {
    for (int i = 0; i < nameStudent.size(); ++i) {
        for (vector<string>::iterator it = (_students[nameStudent[i]][nameSubject]).begin();
             it < (_students[nameStudent[i]][nameSubject]).end(); ++it) {
            if ((*it) == mark) {
                *it = "";
                break;
            }
        }
    }
}

void DeleteEqualMarks(vector<string> nameStudent, string nameSubject, string mark) {
    for (int i = 0; i < nameStudent.size(); ++i) {
        for (vector<string>::iterator it = (_students[nameStudent[i]][nameSubject]).begin();
             it < (_students[nameStudent[i]][nameSubject]).end(); ++it) {
            if ((*it) == mark) {
                *it = "";
            }
        }
    }
}


void DeleteMarkPosition(vector<string> nameStudent, string nameSubject, string position) {
    int pos = stoi(position);
    for (int i = 0; i < nameStudent.size(); ++i) {
        if (pos > 0 && pos <= (_students[nameStudent[i]][nameSubject]).size()) {
            (_students[nameStudent[i]][nameSubject])[pos-1] = "";
        }
    }
}