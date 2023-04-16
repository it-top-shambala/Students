#pragma once
#include "IncludingLibraries.h"
#include "AliasesOfTypes.h"

void WriteToFile(ofstream &file, Students &students) {
    const string tagName = "name"; //tag1
    const string tagSubject = "sub"; //tag2
    const string tagMarks = "marks"; //tag3

    for (auto itemName: students) {
        file << tagName << ";" << itemName.first << ";" << "\n";
        for (auto itemsubject: itemName.second) {
            file << tagSubject << ";" << itemsubject.first << ";" << tagMarks << ";";
            for (auto itemMark: itemsubject.second) {
                file << itemMark << ";";
            }
            file << endl;
        }
        file << endl;
    }
}

bool ExportParsingDataToFile(Students &students) {
    ofstream file;
    string path = "DataStudents.csv";
    file.open(path, ios::trunc);
    if (!file.is_open()) {
        file.close();
        return false;
    }
    WriteToFile(file, students);
    file.close();
    return true;
}

void ReadFromFile(ifstream &file, Students &students) {
    const string tagName = "name";
    const string tagSubject = "sub";
    const string tagMarks = "marks";

    string nameStudents;
    string line;

    while (getline(file, line)) {

        int position = line.find(";");
        string parsingName = line.substr(0, position);
        if (parsingName == tagName) {
            line = line.substr(++position);
            position = line.find(";");
            nameStudents = line.substr(0, position);
            students.insert(Student (nameStudents, {}));
        } else if (parsingName == tagSubject) {
            line = line.substr(++position);
            position = line.find(";");
            string parsingSubject = line.substr(0, position);
            students[nameStudents].insert(Subject (parsingSubject, {}));

            line = line.substr(++position);
            position = line.find(";");
            string parsingMarks = line.substr(0, position);
            if (parsingMarks == tagMarks) {
                line = line.substr(++position);
                vector<string> marks;
                string number = "";
                for (int i = 0; i < line.size();) {
                    if (line[i] != ';') {
                        number += line[i];
                        ++i;
                    } else {
                        students[nameStudents][parsingSubject].push_back(number);
                        number = "";
                        ++i;
                    }
                }
            }
        }
    }
}

bool ImportParsingDataFromFile(map<string, map<string, vector<string>>> &students) {
    ifstream file;
    file.open("DataStudents.csv");
    if (!file.is_open()) {
        file.close();
        return false;
    }

    ReadFromFile(file, students);
    file.close();
    return true;
}

