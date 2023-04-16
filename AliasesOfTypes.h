#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using Mark = string;
using Marks = vector<Mark>;

using Subject = pair<string, Marks>;
using Subjects = map<string, Marks>;

using Student = pair<string, Subjects>;
using Students = map<string, Subjects>;

//map <Students, map<Subjects, vector<Marks>>>
//map <string, map<string, vector<string>>>

