/*
 * Студент 1:
 *      Предмет 1: 5,5,4,1
 *      Предмет 2: 5,5,4,1
 *      Предмет 3: 5,5,4,1
* Студент 2:
 *      Предмет 1: 5,5,4,1
 *      Предмет 6: 5,5,4,1
 *      Предмет 3: 5,5,4,1
 */

#pragma once
#include <string>
#include <map>
#include "subject.h"
struct Student {
    string name;
    map<std::string, Subject> subjects;
};

map<std::string, Student> students;
