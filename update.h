#pragma once
#include <string>
#include <vector>
#include <map>
#include "student.h"
#include "mark.h"

void UpdateMark(string student_name, string subject_name, int mark_index, Mark new_mark) {
    students[student_name].subjects[subject_name].marks[mark_index] = new_mark;
}