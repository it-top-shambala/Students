#include <iostream>

#include "Students.h"
#include "ConsoleHelper.h"

int main() {
    system("chcp 65001");
    string student_name = "Andrey";
    string subject_name_1 = "SoftDev";
    string subject_name_2 = "Photo";
    string subject_name_3 = "DB";
    InsertStudent(student_name);

    InsertSubject(student_name, subject_name_1);
    InsertMark(student_name, subject_name_1, "2");
    InsertMark(student_name, subject_name_1, "3");
    InsertMark(student_name, subject_name_1, "4");
    InsertMark(student_name, subject_name_1, "5");

    InsertSubject(student_name, subject_name_2);
    InsertMark(student_name, subject_name_2, "2");
    InsertMark(student_name, subject_name_2, "2");
    InsertMark(student_name, subject_name_2, "R");
    InsertMark(student_name, subject_name_2, "O");

    InsertMark(student_name, subject_name_3, "-1");

    PrintStudents();

    int choice;
    string name, subject, mark, old_mark, new_mark, filename;

    int input = -1;
    while (input != 0) {
        ShowMenu();
        cout << "Укажите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите имя студента: ";
                cin >> name;
                InsertStudent(name);
                break;
            case 2:
                cout << "Введите имя студента: ";
                cin >> name;
                cout << "Введите название предмета: ";
                cin >> subject;
                InsertSubject(name, subject);
                break;
            case 3:
                cout << "Введите имя студента: ";
                cin >> name;
                cout << "Введите название предмета: ";
                cin >> subject;
                cout << "Введите оценку: ";
                cin >> mark;
                InsertMark(name, subject, mark);
                break;
            case 4:
                cout << "Введите имя студента: ";
                cin >> name;
                RemoveStudent(name);
                break;
            case 5:
                cout << "Введите имя студента: ";
                cin >> name;
                cout << "Введите название предмета: ";
                cin >> subject;
                RemoveSubject(name, subject);
                break;
            case 6:
                cout << "Введите имя студента: ";
                cin >> name;
                cout << "Введите название предмета: ";
                cin >> subject;
                cout << "Введите удаляемую оценку: ";
                cin >> mark;
                RemoveMark(name, subject, mark);
                break;
            case 7:
                cout << "Введите имя студента: ";
                cin >> name;
                cout << "Введите название предмета: ";
                cin >> subject;
                cout << "Введите старую оценку: ";
                cin >> old_mark;
                cout << "Введите новую оценку: ";
                cin >> new_mark;
                UpdateMark(name, subject, old_mark, new_mark);
                break;
            case 8:
                cout << "Введите название файла для экспорта данных: ";
                cin >> filename;
                ExportData(filename);
                break;
            case 9:
                cout << "Введите название файла для импорта данных: ";
                cin >> filename;
                ImportData(filename);
                break;
            case 0:
                cout << "Выход";
                input = 0;
                break;
            default:
                cout << "Нет такого пункта меню!";
                break;

        }
    }

        return 0;
    }
