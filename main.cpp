#include <iostream>

#include "Students.h"
#include "ConsoleHelper.h"

int main() {
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

    return 0;
}
