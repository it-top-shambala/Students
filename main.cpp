#pragma once

#include "Students.h"
#include "ConsoleHelper.h"
#include "FileHelper.h"

int main() {
    system("chcp 65001");
    cout << "|----------------------------------------|" << endl;
    cout << "|          ЖУРНАЛ ПРЕПОДАВАТЕЛЯ          |" << endl;
    cout << "|----------------------------------------|" << endl;

    cout << "Программа формирует список студентов, предметы, которые они изучают и оценки по каждому предмету";
    cout << "в следующем виде:" << endl;

    cout << "----------------------------------------" << endl;
    cout << "Имя студента:" << endl;
    cout << "Предмет 1 :" << " оценка, оценка, оценка..." << endl;
    cout << "Предмет 2 :" << " оценка, оценка, оценка..." << endl;
    cout << "Предмет 3 :" << " оценка, оценка, оценка..." << endl;
    cout << "..." << endl;
    cout << "----------------------------------------" << endl;

    cout << "Интерфейс пользователя:" << endl;
    cout << "КОД:" << " e1 :" << endl; //e - от слова enter ввести данные
    cout << " - " << "Программа предлагает ввести(добавить) список студентов через \",\", которые будут учиться. (Имена должны быть уникальными)" << endl;
    cout << "КОД:" << " e2 :" << endl;
    cout << " - " << "Программа предлагает ввести(добавить) список предметов через \",\", которые будут учить все студенты."<< endl;
    cout << "КОД:" << " e3 :" << endl;
    cout << " - " << "Программа предлагает ввести(добавить) предмет конкретному студенту."<< endl;
    cout << "------------------------------------------------"<<endl;
    cout << "КОД:" << " p1 :" << endl; //p - от слова print напечатать
    cout << " - " << "Программа выводит список студентов." << endl;
    cout << "КОД:" << " p2 :" << endl;
    cout << " - " << "Программа выводит список студентов, предметы, которые они изучают и их оценки." << endl;
    cout << "------------------------------------------------"<<endl;
    cout << "КОД:" << " um1 :" << endl; //u - от слова обновить
    cout << " - " << "Программа добавляет новую оценку у конкретного студента." << endl;
    cout << "КОД:" << " um2 :" << endl; //u - от слова обновить
    cout << " - " << "Программа обновляет первую совпадающую оценку на новую у конкретного студента." << endl;
    cout << "КОД:" << " um3 :" << endl;
    cout << " - " << "Программа обновляет совпадающую оценку по ее позиции." << endl;
    cout << "------------------------------------------------"<<endl;
    cout << "КОД:" << " d1 :" << endl; //d - от слова delete удалить
    cout << " - " << "Программа удаляет конкретного студента по имени." << endl;
    cout << "КОД:" << " d2 :" << endl;
    cout << " - " << "Программа удаляет конкретный предмет у всех студентов." << endl;
    cout << "КОД:" << " d2-1 :" << endl;
    cout << " - " << "Программа удаляет конкретный предмет у конкретного студентов." << endl;
    cout << "------------------------------------------------"<<endl;
    cout << "КОД:" << " dm1 :" << endl;
    cout << " - " << "Программа удаляет оценку у конкретного студентов." << endl;
    cout << "------------------------------------------------"<<endl;
    cout << "КОД:" << " w :" << endl;
    cout << " - " << "Программа записывает изменения в журнал." << endl;
    cout << "КОД:" << " r :" << endl;
    cout << " - " << "Программа считывает данные из журнала." << endl;
    cout << "РАБОТА ПРОГРАММЫ ЗАВЕРШАЕТСЯ ПРИ ЗАПИСИ ДАННЫХ В ФАЙЛ."<<endl;

    bool isRead = true;

    while (isRead) {
        string code;
        cout << "Введите КОД для выбора действий: ";
        getline(cin, code, '\n');
        if (code == "e1") {
            cout << "Введите список студентов через \",\", которые будут учиться. (Имена должны быть уникальными)" << endl;
            string temp;
            getline(cin, temp, '\n');
            ParsingEnteredStudentsName(temp);
        } else if (code == "e2")
        {
            cout << "Введите список предметов через \",\", которые будут учить все студенты." << endl;
            string temp;
            getline(cin, temp, '\n');
            ParsingEnteredStudentsSubjects(temp);
        }
        else if (code == "e3")
        {
            cout << "Добавить предмет конкретному студенту:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            InsertSubject(tempName, tempSubject);
        }
        else if (code == "p1")
        {
            cout << "В журнале следующие студенты:" << endl;
            PrintListStudents();
        }
        else if (code == "p2")
        {
            cout << "Оценки студентов:" << endl;
            PrintStudents();
        }
        else if (code == "um1")
        {
            cout << "Добавить оценку по предмету у конкретного студента:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            cout << "Введите оценку:";
            string tempMark;
            getline(cin, tempMark, '\n');
            UpdateMark({tempName}, tempSubject, tempMark);
        }
        else if (code == "um2")
        {
            cout << "Заменить первую совпадающую оценку по предмету у конкретного студента:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            cout << "Введите старую оценку:";
            string tempMarkOld;
            getline(cin, tempMarkOld, '\n');
            cout << "Введите новую оценку:";
            string tempMarkNew;
            getline(cin, tempMarkNew, '\n');
            UpdateMark(tempName, tempSubject, tempMarkOld, tempMarkNew);
        }
        else if (code == "um3")
        {
            cout << "Заменить первую совпадающую оценку по предмету у конкретного студента:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            cout << "Введите позицию оценки:";
            string tempPosition;
            getline(cin, tempPosition, '\n');
            cout << "Введите оценку:";
            string tempMark;
            getline(cin, tempMark, '\n');
            UpdateMarkPosition({tempName}, tempSubject, tempPosition, tempMark);
        }
        else if (code == "d1")
        {
            cout << "Удалить следующего студента:" << endl;
            string temp;
            getline(cin, temp, '\n');
            DeleteStudent({temp});
        }
        else if (code == "d2")
        {
            cout << "Удалить предмет у всех студентов:" << endl;
            string temp;
            getline(cin, temp, '\n');
            DeleteSubject(temp);
        }
        else if (code == "d2-1")
        {
            cout << "Удалить предмет у студента:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            DeleteSubject({tempName}, tempSubject);
        }
        else if (code == "dm1")
        {
            cout << "Удалить оценку у студента:" << endl;
            cout << "Введите имя студента:";
            string tempName;
            getline(cin, tempName, '\n');
            cout << "Введите предмет студента:";
            string tempSubject;
            getline(cin, tempSubject, '\n');
            cout << "Введите позицию оценки:";
            string tempPosition;
            getline(cin, tempPosition, '\n');
            DeleteMarkPosition({tempName}, tempSubject, tempPosition);
        }
        else if(code == "w")
        {
            if(ExportParsingDataToFile(_students))
            {
                cout << "Данные успешно записаны в журнал" << endl;
                isRead = false;
            }
            else
            {
                cout << "Файл не открылся, что-то с файлом" << endl;
                isRead = false;
            }
        }
        else if(code == "r")
        {
            if(ImportParsingDataFromFile(_students))
            {
                cout << "Данные успешно считаны из журнала" << endl;
            }
            else
            {
                cout << "Файл не открылся, что-то с файлом" << endl;
                isRead = false;
            }
        }
    }

    cout << "ВЫ ВЫШЛИ ИЗ ПРОГРАММЫ."<<endl;

    return 0;
}
