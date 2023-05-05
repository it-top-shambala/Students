#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

using Mark = string;       //Mark - псевдоним для типа string, используется для хранения оценки по конкретному предмету.
using Marks = vector<Mark>;//Marks - вектор оценок, используется для хранения оценок студента по конкретному предмету.

using Subjects = map<string, Marks>;//Subjects - ассоциативный массив, где ключом является строка с именем предмета, а значением - пара с именем предмета и вектором оценок, используется для хранения информации об оценках студента по всем предметам.
using Subject = pair<string, Marks>;//Subject - пара, состоящая из имени предмета и вектора оценок, используется для хранения информации об оценках студента по конкретному предмету.

using Students = map<string, Subjects>; //Students - ассоциативный массив, где ключом является строка с именем студента, а значением - пара с именем студента и ассоциативным массивом Subjects.
using Student = pair<string, Subjects>;//Student - пара, состоящая из имени студента и ассоциативного массива Subjects.

Students _students;       //Переменная _students типа Students создана для хранения информации об оценках всех студентов.Каждый элемент map соответствует конкретному студенту,
                          //а его значением является ассоциативный массив Subjects, который хранит информацию об оценках этого студента по всем предметам.Таким образом, _students
                          //может использоваться для быстрого доступа к оценкам конкретного студента по всем предметам.


                         //Набор функций для добавления информации об оценках студентов в переменную _students:
                         //Функция InsertStudent принимает строку name, которая представляет имя студента. Она создает пустой ассоциативный массив temp типа Subjects и добавляет новый элемент в переменную _students,
                         // который соответствует студенту с именем name и пустым списком предметов и оценок.
void InsertStudent(string name) {
    Subjects temp;
    _students.insert(Student(name, temp));
}
                        //Функция InsertSubject принимает две строки student_name и subject_name, которые представляют соответственно имя студента и имя предмета. Она создает пустой вектор temp типа Marks и 
                       //добавляет новый элемент в ассоциативный массив, соответствующий студенту student_name, который соответствует предмету subject_name и пустому списку оценок.
void InsertSubject(string student_name, string subject_name) {
    Marks temp;
    _students[student_name].insert(Subject(subject_name, temp));
}
                      //Функция InsertMark принимает три аргумента: student_name, subject_name и mark. Она добавляет оценку mark в вектор оценок, соответствующий студенту student_name и предмету subject_name.
void InsertMark(string student_name, string subject_name, Mark mark) {
    _students[student_name][subject_name].push_back(mark);
}
                      //Функция InsertMarks принимает три аргумента: student_name, subject_name и marks, где marks - вектор оценок.
                      //Она добавляет каждую оценку из вектора marks в вектор оценок, соответствующий студенту student_name и предмету subject_name.
void InsertMarks(string student_name, string subject_name, Marks marks) {
    for (Mark mark : marks) {
        _students[student_name][subject_name].push_back(mark);
    }
}
                     //Набор функций, которые используются для вывода информации об оценках студентов на экран:
                     //Функция PrintMark принимает один аргумент mark, который представляет оценку по конкретному предмету. Она выводит эту оценку на экран, за которой следует запятая и пробел.
void PrintMark(Mark mark) {
    cout << mark << ", ";
}
                    //Функция PrintMarks принимает вектор оценок marks. Она выводит каждую оценку из вектора на экран, используя функцию PrintMark, и затем переходит на новую строку.
void PrintMarks(Marks marks) {
    for (Mark mark : marks) {
        PrintMark(mark);
    }
    cout << endl;
}
                    //Функция PrintSubject принимает пару subject, которая состоит из имени предмета и вектора оценок. Она выводит на экран имя предмета, за которым следует двоеточие, 
                    //а затем вызывает функцию PrintMarks для вывода оценок.
void PrintSubject(Subject subject) {
    cout << subject.first << ": ";
    PrintMarks(subject.second);
}
                    //Функция PrintSubjects принимает ассоциативный массив subjects, который хранит информацию об оценках студента по всем предметам. Она выводит информацию об оценках по каждому предмету, 
                    //используя функцию PrintSubject.
void PrintSubjects(Subjects subjects) {
    for (Subject subject : subjects) {
        PrintSubject(subject);
    }
}
                    //Функция PrintStudent принимает пару student, которая состоит из имени студента и ассоциативного массива Subjects с информацией об оценках по всем предметам. 
                    //Она выводит на экран имя студента, за которым следует двоеточие и переход на новую строку, а затем вызывает функцию PrintSubjects для вывода информации об оценках по всем предметам.
void PrintStudent(Student student) {
    cout << student.first << ":" << endl;
    PrintSubjects(student.second);
}
                    //Функция PrintStudents выводит информацию об оценках всех студентов, используя функцию PrintStudent для каждого студента.
void PrintStudents() {
    for (Student student : _students) {
        PrintStudent(student);
    }
}
                   //Функция загрузки (импорта) из файла 
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
                  //Функция экспорта в файл из файла
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
                   //Функция удаления студента
void RemoveStudent(string student_name) {
    if (_students.find(student_name) == _students.end()) {
        cout << "Error: student " << student_name << " not found" << endl;
        return;
    }

    _students.erase(student_name);

    cout << "Student " << student_name << " removed from the list" << endl;
}
                   //Функция удаления придмета у студента
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
                      //Функция удаления оценки у студента по предмету
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
                       //Функция обновления оценки по придмету у студента
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
    setlocale(LC_ALL, "Rus");
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
Footer
© 2023 GitHub, Inc.
Footer navigation
Terms
Privac