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
        out_file << "Student: " << student_name << endl;

        // Обходим каждый предмет
        for (auto subject : subjects) {
            string subject_name = subject.first;
            auto marks = subject.second;

            // Записываем имя предмета
            out_file  << "\t\t" << subject_name << ": ";

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
