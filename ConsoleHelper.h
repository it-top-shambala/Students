#pragma once

#include <iostream>

#include "Students.h"

using namespace std;

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

void ShowMenu() {
    cout << "1. Добавить студента\n"
         << "2. Добавить студенту предмет\n"
         << "3. Добавить студенту оценку по предмету\n"
         << "4. Удалить студента\n"
         << "5. Удалить предмет у студента\n"
         << "6. Удалить студенту оценку по предменту\n"
         << "7. Обновить студенту оценку по предменту\n"
         << "8. Экспортировать данные в файл\n"
         << "9. Импортировать данные из файла\n"
         << "0. Выход\n";
}
