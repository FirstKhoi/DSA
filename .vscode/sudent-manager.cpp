#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Định nghĩa cấu trúc sinh viên
struct Student {
    string name;
    int id;
    string class_id;
    string phone_number;
    string email;
};

// Hàm để thêm sinh viên vào danh sách
void addStudent(vector<Student>& students) {
    Student student;
    cout << "Enter student name: ";
    getline(cin, student.name);
    cout << "Enter student ID: ";
    cin >> student.id;
    cin.ignore(); // Bỏ qua ký tự newline
    cout << "Enter student class ID: ";
    getline(cin, student.class_id);
    cout << "Enter student phone number: ";
    getline(cin, student.phone_number);
    cout << "Enter student email: ";
    getline(cin, student.email);

    students.push_back(student);
}

// Hàm để hiển thị thông tin sinh viên
void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Name: " << student.name << "\n";
        cout << "ID: " << student.id << "\n";
        cout << "Class: " << student.class_id << "\n";
        cout << "Phone: " << student.phone_number << "\n";
        cout << "Email: " << student.email << "\n";
        cout << "-----------------------------------\n";
    }
}

// Hàm chính
int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "Student Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập lựa chọn

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
