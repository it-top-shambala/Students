#include <iostream>
#include <string>
#include "Students.h"
#include "ConsoleHelper.h"
#include "FileHelper.h"
using namespace std;

int main() {
    system("chcp 65001");
    bool isOver=false;
    while (isOver!=true){
        cout<<"Хотите получить журнал оценок из файла? 1-да любая другая цифра-нет"<<endl;
        int answer;
        cin>>answer;
        if (answer==1){
            cout<<"Введите путь для получения журнала оценок"<<endl;
            string path;
            cin>>path;
            _students= ImportFromFile1(path);
        }
        string name;
        void (*actions[2])(string name)={InsertStudent, DeleteStudent};
        cout<<"Добавить студена 0, удалить студена 1, для выхода нажмите 9"<<endl;
        cin>>answer;
        if (answer==9)
            isOver= true;
        cout <<"Введите имя студента"<<endl;
        cin>>name;
        actions[answer](name);
        cout <<"Добавить предмет 0, удалить предмет 1,для выхода нажмите 9"<<endl;
        cin>>answer;
        if (answer==9)
            isOver= true;
        void (*actions2[2])(string,string) ={InsertSubject,DeleteSubject};
        cout <<"Введите название предмета"<<endl;
        string subj;
        cin>>subj;
        actions2[answer](name,subj);
        cout<<"Добавить оценку 0, удалить последнюю оценку по значению 1, удалить оценку по индексу 2 для выхода нажмите 9"<<endl;
        cin>>answer;
        if (answer==9)
            isOver= true;
        void (*actions3[3])(Students ,string,string, int ) ={InsertMark, DeleteMarkForValue1,DeleteMarkForIndex};
        cin>>answer;
        int mark;
        cout<<" Введите оценку или индекс в случае(2)"<<endl;
        cin>>mark;
        actions3[answer](_students,name,subj,mark);


    }

    return 0;
}
