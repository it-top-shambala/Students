#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Students.h"

using namespace std;

void Export_students(Students& students, string filename) {
    // Открываем файл на запись
    ofstream out_file(filename);

    // Если файл не открылся, выводим сообщение об ошибке и завершаем функцию
    if (!out_file.is_open()) {
        cerr << "Failed to open file " << endl;
        return;
    }

    // Обходим каждого студента
    for (auto student : students) {
        string student_name = student.first;
        auto subjects = student.second;

        // Записываем имя студента
        out_file << "Student" << "|" << student_name << endl;

        // Обходим каждый предмет
        for (auto subject : subjects) {
            string subject_name = subject.first;
            auto marks = subject.second;

            // Записываем имя предмета
            out_file  << "\t" << subject_name << "| ";

            // Записываем оценки
            for (auto mark : marks) {
                out_file << " " << mark;
            }
            out_file << endl;
        }
    }

    // Закрываем файл
    out_file.close();
}
void ImportFromFile(Students& students){
    ifstream input("ListStud.psv");
    if (!input) {
        cerr << "Can't open file " << endl;
    }

    string line;
    string line1;
    string studentName;
    string subjectName;
    Marks marks;

    while (getline(input, line)) {
        int delimiterPos = line.find("|");
        if (delimiterPos == string::npos ) {
            cerr << "Invalid file format" << endl;
        }
        line1 = line.substr(0,delimiterPos);
        if (line1 == "Student"){
            studentName = line.substr(delimiterPos + 1);
            _students.insert(pair(studentName,Subjects()));
        } else if (line != "Student"){
            subjectName = line.substr(0,delimiterPos);
            string marksStr = line.substr(delimiterPos + 1);
            marks.clear();

            while (!marksStr.empty()) {
                int Pos = marksStr.find(" ");
                if (Pos == string::npos) {
                    marks.push_back(marksStr);
                    marksStr.clear();
                } else {
                    string mark = marksStr.substr(0, Pos);
                    marks.push_back(mark);
                    marksStr.erase(0,Pos + 1);
                }
            }

            _students[studentName][subjectName] = marks;

        }



    }
}


