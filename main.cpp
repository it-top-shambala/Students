#include <iostream>
#include "Update.h"
#include "Impexp.h"
#include "Students.h"
#include "ConsoleHelper.h"
#include "Remove.h"
using namespace std;
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
            ExportDataToFile("temp.txt");
            PrintStudents();
            break;
        }
              //Remove Student
        case 3: {
            string student_name;
            cout << "Enter the name of the student to remove: ";
            cin >> student_name;
            RemoveStudent(student_name);
            PrintStudents();
            break;
        }
              //Remove a subject
        case 4: {
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