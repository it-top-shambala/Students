#include "mark.h"
#include "subject.h"
#include "student.h"
#include "print.h"
#include "insert.h"
#include "delete.h"
#include "update.h"

using namespace std;

int main() {
    string student_name = "Andrey";
    string subject_name_1 = "SoftDev";
    string subject_name_2 = "Photo";
    string subject_name_3 = "DB";
    InsertStudent(student_name);

    InsertSubject(student_name, subject_name_1);
    InsertMark(student_name, subject_name_1, { "2" });
    InsertMark(student_name, subject_name_1, { "3" });
    InsertMark(student_name, subject_name_1, { "4" });
    InsertMark(student_name, subject_name_1, { "5" });

    InsertSubject(student_name, subject_name_2);
    InsertMark(student_name, subject_name_2, { "2" });
    InsertMark(student_name, subject_name_2, { "2" });
    InsertMark(student_name, subject_name_2, { "R" });
    InsertMark(student_name, subject_name_2, { "O" });

    InsertMark(student_name, subject_name_3, { "-1" });
    int option;
    do {
        cout << "Select an option: " << endl;
        cout << "1. Update a mark" << endl;
        cout << "2. Delete a mark" << endl;
        cout << "3. Delete a subject" << endl;
        cout << "4. Delete a student" << endl;
        cout << "5. Export data" << endl;
        cout << "6. Import data" << endl;
        cout << "7. Exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            // Update a mark

            UpdateMark(student_name, subject_name_2, 2, { "4" }); // update the third mark of SoftDev subject to 4
            cout << "After updating a mark:" << endl;
            PrintStudents();
            break;
        case 2:
            // Delete a mark
            DeleteMark(student_name, subject_name_1, 0); // delete the first mark from SoftDev subject
            cout << "After deleting a mark:" << endl;
            PrintStudents();
            break;
        case 3:
            // Delete a subject
            DeleteSubject(student_name, subject_name_2); // delete the Photo subject
            cout << "After deleting a subject:" << endl;
            PrintStudents();
            break;
        case 4:
            // Delete a student
            DeleteStudent(student_name); // delete the Andrey student
            cout << "After deleting a student:" << endl;
            PrintStudents();
            break;
        case 5:
            // Export data to a file
            ExportData("students1.txt");
            // Print imported data
            cout << "Export data:" << endl;
            PrintStudents();
            break;
        case 6:
            // Import data to a file
            ImportData("students.txt");

            // Print imported data
            cout << "Imported data:" << endl;
            PrintStudents();
            break;
            
        case 7:
            // Exit the program
            break;
        default:
            cout << "Invalid option. Please enter a number between 1 and 7." << endl;
            break;
        }
    } while (option != 7);
    return 0;
}
   
    
           






    
    

    

    
    
    
 