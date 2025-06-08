#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    int numEmployees;

    cout << "Nhap so luong nhan vien: ";
    cin >> numEmployees;
    cin.ignore(); 

    vector<string> names(numEmployees);
    vector<string> phones(numEmployees);
    vector<double> salaries(numEmployees);
    double totalSalary = 0;

    // Nhập thông tin
    for (int i = 0; i < numEmployees; ++i) {
        cout << "\nNhap thong tin cho nhan vien thu " << i + 1 << ":\n";

        cout << "Ten nhan vien: ";
        getline(cin, names[i]);

        cout << "So dien thoai: ";
        getline(cin, phones[i]);

        cout << "Luong (VND): ";
        cin >> salaries[i];
        cin.ignore(); 
    }

    cout << "\n";
    cout << left << setw(20) << "Ten Nhan Vien"
         << setw(15) << "Phone Num"
         << right << setw(12) << "Salary (VND)" << endl;
    cout << setfill('-') << setw(47) << "-" << setfill(' ') << endl;

    for (int i = 0; i < numEmployees; ++i) {
        cout << left << setw(20) << names[i]
             << setw(15) << phones[i]
             << right << setw(12) << fixed << setprecision(0) << salaries[i] << endl;
        totalSalary += salaries[i];
    }

    cout << setfill('-') << setw(47) << "-" << setfill(' ') << endl;
    cout << left << setw(35) << "Tong Salary:"
         << right << setw(12) << fixed << setprecision(0) << totalSalary << endl;

    return 0;
}
