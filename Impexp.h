#pragma once
#include "Students.h"
#include <fstream>
using namespace std;

void LoadDataFromFile(const string& filename) {
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "Error: could not open file " << filename << endl;
        return;
    }

    vector<string> file_lines;
    string line;
    while (getline(input_file, line)) {
        file_lines.push_back(line);
    }

    input_file.close();

    for (const auto& line : file_lines) {
        vector<string> tokens;
        size_t start_pos = 0, end_pos = 0;
        while ((end_pos = line.find(' ', start_pos)) != string::npos) {
            tokens.push_back(line.substr(start_pos, end_pos - start_pos));
            start_pos = end_pos + 1;
        }
        tokens.push_back(line.substr(start_pos));

        if (tokens.size() < 2) {
            cout << "Error: invalid line in file " << filename << endl;
            continue;
        }

        string student_name = tokens[0];
        string subject_name = tokens[1];
        Marks marks;
        for (size_t i = 2; i < tokens.size(); i++) {
            marks.push_back(tokens[i]);
        }

        InsertStudent(student_name);
        InsertSubject(student_name, subject_name);
        InsertMarks(student_name, subject_name, marks);
    }
}
void ExportDataToFile(const string& filename) {
    ofstream output_file(filename);
    if (!output_file.is_open()) {
        cout << "Error: could not create file " << filename << endl;
        return;
    }

    for (const auto& student : _students) {
        const string& student_name = student.first;
        const Subjects& subjects = student.second;
        for (const auto& subject : subjects) {
            const string& subject_name = subject.first;
            const Marks& marks = subject.second;
            output_file << student_name << " " << subject_name;
            for (const auto& mark : marks) {
                output_file << " " << mark;
            }
            output_file << endl;
        }
    }

    output_file.close();
}