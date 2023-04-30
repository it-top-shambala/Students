#include "mark.h"
#include "subject.h"
#include "student.h"
#include "print.h"
#include "insert.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;






void DeleteMark(string student_name, string subject_name, int mark_index) {
    students[student_name].subjects[subject_name].marks.erase(students[student_name].subjects[subject_name].marks.begin() + mark_index);
}

void DeleteSubject(string student_name, string subject_name) {
    students[student_name].subjects.erase(subject_name);
}

void DeleteStudent(string student_name) {
    students.erase(student_name);
}
void UpdateMark(string student_name, string subject_name, int mark_index, Mark new_mark) {
    students[student_name].subjects[subject_name].marks[mark_index] = new_mark;
}
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
int main() {
    string student_name = "Andrey";
    string subject_name_1 = "SoftDev";
    string subject_name_2 = "Photo";
    string subject_name_3 = "DB";
    InsertStudent(student_name);

    InsertSubject(student_name, subject_name_1);
    InsertMark(student_name, subject_name_1, { "2" });
    InsertMark(student_name, subject_name_1, { "3" });
    InsertMark(student_name, subject_name_1, { "4" });
    InsertMark(student_name, subject_name_1, { "5" });

    InsertSubject(student_name, subject_name_2);
    InsertMark(student_name, subject_name_2, { "2" });
    InsertMark(student_name, subject_name_2, { "2" });
    InsertMark(student_name, subject_name_2, { "R" });
    InsertMark(student_name, subject_name_2, { "O" });

    InsertMark(student_name, subject_name_3, { "-1" });
    int option;
    do {
        cout << "Select an option: " << endl;
        cout << "1. Update a mark" << endl;
        cout << "2. Delete a mark" << endl;
        cout << "3. Delete a subject" << endl;
        cout << "4. Delete a student" << endl;
        cout << "5. Export data" << endl;
        cout << "6. Import data" << endl;
        cout << "7. Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            // Update a mark

            UpdateMark(student_name, subject_name_2, 2, { "4" }); // update the third mark of SoftDev subject to 4
            cout << "After updating a mark:" << endl;
            PrintStudents();
            break;
        case 2:
            // Delete a mark
            DeleteMark(student_name, subject_name_1, 0); // delete the first mark from SoftDev subject
            cout << "After deleting a mark:" << endl;
            PrintStudents();
            break;
        case 3:
            // Delete a subject
            DeleteSubject(student_name, subject_name_2); // delete the Photo subject
            cout << "After deleting a subject:" << endl;
            PrintStudents();
            break;
        case 4:
            // Delete a student
            DeleteStudent(student_name); // delete the Andrey student
            cout << "After deleting a student:" << endl;
            PrintStudents();
            break;
        case 5:
            // Export data to a file
            ExportData("students1.txt");
            // Print imported data
            cout << "Export data:" << endl;
            PrintStudents();
            break;
        case 6:
            // Import data to a file
            ImportData("students.txt");

            // Print imported data
            cout << "Imported data:" << endl;
            PrintStudents();
            break;
            
        case 7:
            // Exit the program
            break;
        default:
            cout << "Invalid option. Please enter a number between 1 and 7." << endl;
            break;
        }
    } while (option != 7);
    return 0;
}
   
    
           






    
    

    

    
    
    
 