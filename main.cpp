#include <iostream>

#include "Students.h"
#include "ConsoleHelper.h"

int main() {
    string student_name1 = "Nikolay";
    string subject_name1 = "Math";
    string subject_name2 = "Photo";
    string subject_name3 = "History";

    InsertStudent(student_name1);

    InsertSubject(student_name1, subject_name1);
    InsertMark(student_name1,subject_name1,"2");
    InsertMark(student_name1,subject_name1,"3");
    InsertMark(student_name1,subject_name1,"4");
    InsertMark(student_name1,subject_name1,"5");

    InsertSubject(student_name1, subject_name2);
    InsertMark(student_name1,subject_name2,"3");
    InsertMark(student_name1,subject_name2,"3");
    InsertMark(student_name1,subject_name2,"3");
    InsertMark(student_name1,subject_name2,"4");
    InsertMark(student_name1,subject_name3,"4");

    string student_name2 = "Ivan";
    string subject_name4 = "Physic";
    string subject_name5 = "Graph";
    InsertSubject(student_name2, subject_name1);
    InsertMark(student_name2,subject_name1,"2");
    InsertMark(student_name2,subject_name1,"3");
    InsertMark(student_name2,subject_name1,"3");
    InsertMark(student_name2,subject_name1,"4");

    InsertSubject(student_name2, subject_name4);
    InsertMark(student_name2,subject_name4,"5");
    InsertMark(student_name2,subject_name4,"4");
    InsertMark(student_name2,subject_name4,"3");
    InsertMark(student_name2,subject_name4,"2");
    InsertMark(student_name2,subject_name4,"3");

    InsertMark(student_name2,subject_name5,"5");
    InsertMark(student_name2,subject_name5,"5");
    InsertMark(student_name2,subject_name5,"5");
    InsertMark(student_name2,subject_name5,"4");
    InsertMark(student_name2,subject_name5,"4");

    string student_name3 = "Igor";
    string subject_name6 = "Football";
    string subject_name7 = "Gym";
    InsertSubject(student_name3, subject_name6);
    InsertMark(student_name3,subject_name6,"5");
    InsertMark(student_name3,subject_name6,"5");
    InsertMark(student_name3,subject_name6,"5");
    InsertSubject(student_name3, subject_name7);
    InsertMark(student_name3,subject_name7,"5");
    InsertMarks(student_name3, subject_name7, {"s", "R", "Z"});

    PrintStudents();

    DeleteMark(student_name1,subject_name2,2);
    PrintStudents();

    DeleteSubject(student_name1,subject_name2);
    PrintStudents();

    DeleteStudent(student_name1);
    PrintStudents();





    return 0;
}
