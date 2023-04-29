#pragma once

#include "Students.h"
#include "ConsoleHelper.h"

using namespace std;

/*void ExportData(string filename) {
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
*/

void WriteSubjectData(const Subject& subject, ofstream& outfile) {
    outfile << subject.first;

    for (auto& mark : subject.second) {
        outfile << mark << ",";
    }

    outfile << endl;
}

void WriteStudentData(const Student& student, ofstream& outfile) {
    outfile << student.first;

    for (auto& subject : student.second) {
        WriteSubjectData(subject, outfile);
    }

    outfile << endl;
}

void ExportData(string filename) {
    ofstream outfile(filename);

    for (auto& student : _students) {
        WriteStudentData(student, outfile);
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