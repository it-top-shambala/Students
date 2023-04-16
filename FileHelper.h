#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

using Mark = string;
using Marks = vector<Mark>;

using Subjects = map<string, Marks>;
using Subject = pair<string, Marks>;

using Students = map<string, Subjects>;
using Student = pair<string, Subjects>;

map <string,map<string,vector<string>>>ImortToFile(string path){

}
Students ImportFromFile1(string path){
    Students result;
    ifstream file;
    file.open(path);
    if (!file.is_open())
        cerr<<"Error"<<endl;
    Subjects subjects;
    Marks marks;
    string name;
    string subject;
    string line;
    while (getline(file,line,'-')){
        name=line;
        while (getline(file,line,':')){
            subject=line;
            while (getline(file,line,' ')){
                marks.push_back(line);
            }
            subjects.insert(pair<string ,Marks>(subject,marks));
        }
      result.insert(pair<string,Subjects>(name,subjects));
    }
    file.close();
    return result;
}
string Parser(string& str,char findedChar){
    string result=str.substr(0,str.find(findedChar));
    str=str.substr(str.find(findedChar)+1);
    return result;
}
Students ImportFromFile2(string path,string Parser(string& str,char findedChar)) {
    Students result;
    ifstream file;
    file.open(path);
    if (!file.is_open())
        cerr << "Error" << endl;
    Subjects subjects;
    Mark mark;
    Marks marks;
    string name;
    string subject;
    string line;
    while (getline(file,line)){
        name= Parser(line,'-');
        subject= Parser(line,':');
        while (line.empty()){
            mark= Parser(line,' ');
            marks.push_back(mark);
        }
        marks.push_back(line);
        subjects.insert(pair<string,Marks>(subject,marks));
    }
    result.insert(pair<string,Subjects>(name,subjects));
    file.close();
    return result;
}
void ExportToFile()