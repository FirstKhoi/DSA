#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definitions
void bai1(int a, int b) {
    cout << a / b << " " << a % b << endl;
}

void bai2(int x) {
    cout << x * x * x + 3 * x * x + x + 1 << endl;
}

void bai3(int a, int b, int c) {
    cout << a * (b + c) + b * (a + c) << endl;
}

void bai4(int a, int b) {
    cout << a + b << " " << a - b << " " << a * b << " " << fixed << setprecision(2) << (double)a / b << endl;
}

void bai5(int r) {
    double pi = 3.141592653589793;
    cout << fixed << setprecision(2) << 2 * pi * r << " " << pi * r * r << endl;
}

void bai6(int x1, int y1, int x2, int y2) {
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << fixed << setprecision(2) << distance << endl;
}

void bai7(int c) {
    cout << fixed << setprecision(2) << (c * 9.0 / 5.0) + 32 << endl;
}

void bai8(int n) {
    cout << (long long)n * (n + 1) / 2 << endl;
}

void bai9(int n) {
    cout << (long long)n * (n + 1) * (2 * n + 1) / 6 << endl;
}

void bai10(int n) {
    double result = (double)n / (n + 1);
    cout << fixed << setprecision(2) << result << endl;
}

void bai11(int n) {
    cout << (long long)n * (n + 1) << endl;
}

void bai12(long long n) {
    if (n % 2 == 0)
        cout << n / 2 * n / 2 << endl;
    else
        cout << n * (n + 1) / 2 << endl;
}

void bai13(int a, int b) {
    cout << a / b * b << endl;
}

void bai14(int a, int b) {
    cout << ((a + b - 1) / b) * b << endl;
}

void bai15(int n) {
    cout << (n % 3 == 0 && n % 5 == 0) << endl;
}

void bai16(int n) {
    if (n <= 0)
        cout << "INVALID" << endl;
    else if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void bai17(int t, int n) {
    if (t < 1 || t > 12 || n <= 0)
        cout << "INVALID" << endl;
    else {
        if (t == 2) {
            if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
                cout << 29 << endl;
            else
                cout << 28 << endl;
        } else if (t == 4 || t == 6 || t == 9 || t == 11)
            cout << 30 << endl;
        else
            cout << 31 << endl;
    }
}

void bai18(char c) {
    cout << (islower(c) ? "YES" : "NO") << endl;
}

void bai19(char c) {
    cout << (isupper(c) ? "YES" : "NO") << endl;
}

void bai20(char c) {
    cout << (isalpha(c) ? "YES" : "NO") << endl;
}

void bai21(char c) {
    cout << (isdigit(c) ? "YES" : "NO") << endl;
}

void bai22(char c) {
    if (isupper(c))
        cout << (char)tolower(c) << endl;
    else
        cout << c << endl;
}

void bai23(char c) {
    if (islower(c))
        cout << (char)toupper(c) << endl;
    else
        cout << c << endl;
}

void bai24(char c) {
    if (isalpha(c)) {
        if (c == 'z')
            cout << 'a' << endl;
        else if (c == 'Z')
            cout << 'A' << endl;
        else
            cout << (char)(c + 1) << endl;
    } else {
        cout << "INVALID" << endl;
    }
}

void bai25(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

void bai26(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
        cout << "INVALID" << endl;
    else if (a == b && b == c)
        cout << "1" << endl; // Tam giác đều
    else if (a == b || b == c || a == c)
        cout << "2" << endl; // Tam giác cân
    else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
        cout << "3" << endl; // Tam giác vuông
    else
        cout << "4" << endl; // Tam giác thường
}

void bai27(long long n) {
    int years = n / 365;
    n %= 365;
    int months = n / 30;
    int days = n % 30;
    cout << years << " " << months << " " << days << endl;
}

void bai28(int a, int b, int c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0)
        cout << "NO" << endl;
    else if (delta == 0)
        cout << fixed << setprecision(2) << -b / (2 * a) << endl;
    else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
    }
}

void bai29(double a, double b) {
    int count = floor(b) - ceil(a) + 1;
    cout << count << endl;
}

void bai30(long long a, long long b, long long c) {
    if (a / b == c || b / c == a || c / a == b)
        cout << "/" << endl;
    else
        cout << "NOSOL" << endl;
}
void bai31(double d1, double d2, double d3, double d4) {
    double result = (d1 + 2 * d2 + 3 * d3 + 4 * d4) / 10.0;
    if (result >= 8)
        cout << "GIOI" << endl;
    else if (result >= 6.5)
        cout << "KHA" << endl;
    else if (result >= 5)
        cout << "TRUNG BINH" << endl;
    else
        cout << "YEU" << endl;
}

void bai32(long long a, long long b, long long c, long long d, long long e) {
    long long arr[] = {a, b, c, d, e};
    sort(arr, arr + 5);
    cout << arr[1] << endl;
}

// Main function
int main() {
    // Example usage of functions (you can replace these with actual input handling)

    bai1(10, 3);
    bai2(5);
    bai3(1, 2, 3);
    bai4(9, 2);
    bai5(7);
    bai6(0, 0, 3, 4);
    bai7(37);
    bai8(10);
    bai9(3);
    bai10(5);
    bai11(6);
    bai12(6);
    bai13(10, 3);
    bai14(10, 3);
    bai15(15);
    bai16(2000);
    bai17(2, 29);
    bai18('a');
    bai19('A');
    bai20('b');
    bai21('1');
    bai22('Z');
    bai23('z');
    bai24('z');
    bai25(3, 4, 5);
    bai26(3, 4, 5);
    bai27(400);
    bai28(1, -2, 1);
    bai29(-1.5, 2.5);
    bai30(9, 3, 3);
    bai31(8.0, 7.0, 6.0, 5.0);
    bai32(10, 20, 30, 40, 50);

    return 0;
}
