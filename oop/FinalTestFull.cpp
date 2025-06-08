#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    char fullName[50];
    float testResult;
};

unsigned int getStringLen(char* str) {
    unsigned int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

void toUpperCase(char* str, char* desStr) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *desStr = *str - 32;
        } else {
            *desStr = *str;
        }
        str++;
        desStr++;
    }
    *desStr = '\0';
}

bool compareStr(char* str1, char* str2) {
    while (*str1 && *str2) {
        char c1 = *str1;
        char c2 = *str2;
        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;
        if (c1 < c2) return true;
        if (c1 > c2) return false;
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 != '\0') return true;
    return false;
}

void myStrCpy(char* src, char* dest) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

void saveStudentToFile(Student* t, const char* fileName) {
    ofstream f_out(fileName);;
    if (!f_out) {
        cout << "Can not open this file!" << endl;
        return;
    }
    f_out.write(reinterpret_cast<char*>(t), sizeof(Student));
    f_out.close();
}

void readStudentFromFile(const char* fileName, bool sorted) {
    ifstream f_in(fileName);
    if (!f_in) {
        cout << "Can not open this file!" << endl;
        return;
    }
    Student arr[100];
    int n = 0;
    while (f_in.read(reinterpret_cast<char*>(&arr[n]), sizeof(Student))) {
        n++;
    }
    f_in.close();
    if (sorted) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!compareStr(arr[i].fullName, arr[j].fullName)) {
                    Student tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i].id << "\t" << arr[i].fullName << endl;
    }
}

int main() {
    int choiceNum;
    char fileName[100] = "students.txt";
    do {
        cout << "Press 1 to solve exercise 1" << endl;
        cout << "Press 2 to solve exercise 2" << endl;
        cout << "Press 3 to solve exercise 3" << endl;
        cout << "Press 0 to quit 0" << endl;
        cout << "Press your choice: ";
        cin >> choiceNum;
        cin.ignore();
        if (choiceNum == 1) {
            Student s;
            cout << "Enter student Id:"; cin >> s.id; cin.ignore();
            cout << "Enter student full name: "; cin.getline(s.fullName, 50);
            cout << "Enter mark of student:"; cin >> s.testResult; cin.ignore();
            saveStudentToFile(&s, fileName);
        } else if (choiceNum == 2) {
            readStudentFromFile(fileName, false);
        } else if (choiceNum == 3) {
            readStudentFromFile(fileName, true);
        } else if (choiceNum == 0) {
            cout << "Exiting program..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choiceNum != 0);
    return 0;
}
