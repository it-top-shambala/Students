#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

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
void PrintMark(Mark mark) {
    cout << mark << ", ";
}

void PrintMarks(Marks marks) {
    for (Mark mark : marks) {
        PrintMark(mark);
    }
    cout << endl;
}

void PrintSubject(Subject subject) {
    cout << subject.first << ": ";
    PrintMarks(subject.second);
}

void PrintSubjects(Subjects subjects) {
    for (Subject subject : subjects) {
        PrintSubject(subject);
    }
}

void PrintStudent(Student student) {
    cout << student.first << ":" << endl;
    PrintSubjects(student.second);
}

void PrintStudents() {
    for (Student student : _students) {
        PrintStudent(student);
    }
}
void LoadDataFromFile(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string student_name, subject_name, mark_str;
        Marks marks;

        istringstream iss(line);
        iss >> student_name >> subject_name;

        while (iss >> mark_str) {
            marks.push_back(mark_str);
        }

        if (_students.find(student_name) == _students.end()) {
            InsertStudent(student_name);
        }

        if (_students[student_name].find(subject_name) == _students[student_name].end()) {
            InsertSubject(student_name, subject_name);
        }

        InsertMarks(student_name, subject_name, marks);
    }

    file.close();
}
void ExportDataToFile(string filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }

    for (const auto& student : _students) {
        file << student.first << ":" << endl;
        for (const auto& subject : student.second) {
            file << subject.first << " ";

            for (const auto& mark : subject.second) {
                file << mark << " ";
            }

            file << endl;
        }
    }

    file.close();
}

void RemoveStudent(string student_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    _students.erase(student_name);

    cout << "Student " << student_name << " removed from the list" << endl;
}
void RemoveSubject(string student_name, string subject_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    auto& subjects = _students[student_name];
    if (subjects.find(subject_name) == subjects.end()) {
        cout << "Error: subject " << subject_name << " not found for student " << student_name << endl;
        return;
    }

    subjects.erase(subject_name);

    cout << "Subject " << subject_name << " removed from student " << student_name << endl;
}
void RemoveMark(string student_name, string subject_name, Mark mark) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    auto& subjects = _students[student_name];
    if (subjects.find(subject_name) == subjects.end()) {
        cout << "Error: subject " << subject_name << " not found for student " << student_name << endl;
        return;
    }

    auto& marks = subjects[subject_name];
    auto it = find(marks.begin(), marks.end(), mark);
    if (it == marks.end()) {
        cout << "Error: mark " << mark << " not found for student " << student_name << " and subject " << subject_name << endl;
        return;
    }

    marks.erase(it);

    cout << "Mark " << mark << " removed from student " << student_name << " and subject " << subject_name << endl;
}
void UpdateMark(string student_name, string subject_name, Mark old_mark, Mark new_mark) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    auto& subjects = _students[student_name];
    if (subjects.find(subject_name) == subjects.end()) {
        cout << "Error: subject " << subject_name << " not found for student " << student_name << endl;
        return;
    }

    auto& marks = subjects[subject_name];
    auto it = find(marks.begin(), marks.end(), old_mark);
    if (it == marks.end()) {
        cout << "Error: mark " << old_mark << " not found for student " << student_name << " and subject " << subject_name << endl;
        return;
    }

    *it = new_mark;

    cout << "Mark " << old_mark << " updated to " << new_mark << " for student " << student_name << " and subject " << subject_name << endl;
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Import from file\n";
        cout << "2. Export from file to file \n";
        cout << "3. Remove a student\n";
        cout << "4. Remove a subject\n";
        cout << "5. Remove a mark\n";
        cout << "6. Update mark in file\n";
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            //Import from file
        case 1: {
            LoadDataFromFile("C:/data.txt");
            PrintStudents();
            break;
        }
              //Export from file to file
        case 2: {
            LoadDataFromFile("C:/data.txt");
            ExportDataToFile("temp.txt");
            PrintStudents();
            break;
        }
              //Remove Student
        case 3: {
            LoadDataFromFile("C:/data.txt");
            string student_name;
            cout << "Enter the name of the student to remove: ";
            cin >> student_name;
            RemoveStudent(student_name);
            PrintStudents();
            break;
        }
              //Remove a subject
        case 4: {
            LoadDataFromFile("C:/data.txt");
            string student_name, subject_name;
            cout << "Enter the name of the student: ";
            cin >> student_name;
            cout << "Enter the name of the subject: ";
            cin >> subject_name;
            RemoveSubject(student_name, subject_name);
            PrintStudents();
            break;
        }
              // Remove a mark
        case 5: {
            LoadDataFromFile("C:/data.txt");
            RemoveMark("Andrey", "DB", "-1");
            PrintStudents();
            break;
        }
              //Update mark in file
        case 6: {
            LoadDataFromFile("C:/data.txt");
            string student_name, subject_name, old_mark, new_mark;
            cout << "Enter the name of the student: ";
            cin >> student_name;
            cout << "Enter the name of the subject: ";
            cin >> subject_name;
            cout << "Enter the old mark: ";
            cin >> old_mark;
            cout << "Enter the new mark: ";
            cin >> new_mark;

            UpdateMark(student_name, subject_name, old_mark, new_mark);

            PrintStudents();
            break;
        }
        case 7:
            // Exit the program
            break;
        default:
            cout << "Invalid option. Please enter a number between 1 and 7." << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}