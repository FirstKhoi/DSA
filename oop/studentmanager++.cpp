#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    int age;
    float gpa;
};

class StudentManagementSystem {
private:
    vector<Student> students;
public:
    void addStudent(Student student) {
        students.push_back(student);
    }

    void removeStudent(string name) {
        for (int i = 0; i < students.size(); ++i) {
            if (students[i].name == name) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    Student findStudent(string name) {
        for (int i = 0; i < students.size(); ++i) {
            if (students[i].name == name) {
                return students[i];
            }
        }
        return {"Not Found", -1, -1};
    }

    void displayAllStudents() {
        for (const auto& student : students) {
            cout << "Name: " << student.name << endl;
            cout << "Age: " << student.age << endl;
            cout << "GPA: " << student.gpa << endl;
            cout << "---------------------------" << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Find Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Student student;
            cout << "Name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Age: ";
            cin >> student.age;
            cout << "GPA: ";
            cin >> student.gpa;
            sms.addStudent(student);
        } else if (choice == 2) {
            string name;
            cout << "Enter the name of the student to remove: ";
            cin.ignore();
            getline(cin, name);
            sms.removeStudent(name);
        } else if (choice == 3) {
            string name;
            cout << "Enter the name of the student to find: ";
            cin.ignore();
            getline(cin, name);
            Student student = sms.findStudent(name);
            if (student.name != "Not Found") {
                cout << "Name: " << student.name << endl;
                cout << "Age: " << student.age << endl;
                cout << "GPA: " << student.gpa << endl;
            } else {
                cout << "Student not found!" << endl;
            }
        } else if (choice == 4) {
            sms.displayAllStudents();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}