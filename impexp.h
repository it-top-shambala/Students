#pragma once
#include <string>
#include <vector>
#include <map>
#include "student.h"
#include "mark.h"

void ExportData(string filename) {
    std::ofstream file(filename);
    for (const auto& [name, student] : students) {
        file << student.name << ":" << endl;
        for (const auto& [name, subject] : student.subjects) {
            file << subject.name << ": ";
            for (const auto& mark : subject.marks) {
                file << mark.value << ", ";
            }
            file << endl;
        }
        file << endl;
    }
    file.close();
    cout << "Data exported to file " << filename << endl;
}

void ImportData(string filename) {
    std::ifstream file(filename);
    string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line.back() == ':') {
            // Student name
            line.pop_back();
            InsertStudent(line);
        }
        else {
            // Subject and marks
            string subject_name = line.substr(0, line.find(":"));
            InsertSubject(students.rbegin()->first, subject_name);
            line = line.substr(line.find(":") + 1);
            while (!line.empty()) {
                string mark_value;
                if (line.find(", ") != string::npos) {
                    mark_value = line.substr(0, line.find(", "));
                    line = line.substr(line.find(", ") + 2);
                }
                else {
                    mark_value = line;
                    line = "";
                }
                InsertMark(students.rbegin()->first, subject_name, { mark_value });
            }
        }
    }
    file.close();
    cout << "Data imported from file " << filename << endl;
}