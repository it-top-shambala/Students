#include <iostream>

#include "Students.h"
#include "ConsoleHelper.h"
#include "FileHelper.h"

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

    Student Roman = pair("Roman",Subjects());
    Roman.second["Chem"] = Marks {"L","S","D"};
    Roman.second["Bio"] = Marks {"G","S","M"};
    _students.insert(pair(Roman.first,Roman.second));

    char mode;
    do{
        cout << "0 - Show all list" << endl;
        cout << "1 - Delete Student" << endl;
        cout << "2 - Delete Subject" << endl;
        cout << "3 - Delete Mark" << endl;
        cout << "4 - Update Mark" << endl;
        cout << "e - EXIT" << endl;

        cin >> mode;
        if (mode == '0'){
            PrintStudents();
        } else if (mode == '1'){
            cout << "Input student name : " << endl;
            string student_name;
            cin >> student_name;
            DeleteStudent(student_name);
            cout << "-------------" ;
            PrintStudents();
        } else if (mode == '2'){
            cout << "Input student name : " << endl;
            string student_name;
            cin >> student_name;
            cout << "Input subject : " << endl;
            string subject_name;
            cin >> subject_name;
            DeleteSubject(student_name,subject_name);
            PrintStudents();
        } else if (mode == '3'){
            cout << "Input student name : " << endl;
            string student_name;
            cin >> student_name;
            cout << "Input subject : " << endl;
            string subject_name;
            cin >> subject_name;
            cout << "Input position of mark : " << endl;
            int pos;
            cin >> pos;
            DeleteMark(student_name, subject_name,pos);
            PrintStudents();
        } else if (mode == '4'){
            cout << "Input student name : " << endl;
            string student_name;
            cin >> student_name;
            cout << "Input subject : " << endl;
            string subject_name;
            cin >> subject_name;
            cout << "Input position of mark : " << endl;
            int pos;
            cin >> pos;
            cout << "Input new mark : " << endl;
            string new_mark;
            cin >> new_mark;
            UpdateMark(student_name, subject_name,pos,new_mark);
            PrintStudents();
        }
    } while (mode != 'e');


//vector<string> rez = ImportFromFile("ListStud.psv");
//    for (int i = 0; i < rez.size(); ++i) {
//        cout << rez[i] <<endl;
//    }

    return 0;
}
