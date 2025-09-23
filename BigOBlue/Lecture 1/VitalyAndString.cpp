#include<iostream>
#include<string>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3808/problems/493?view=statement
int main(){
    string s, t; cin >> s >> t;
    
    // Tạo bản sao của s
    string result = s;
    
    // Bắt đầu từ ký tự cuối cùng, tìm ký tự có thể tăng
    int i = result.size() - 1;
    while(i >= 0) {
        if(result[i] < 'z') {
            result[i]++;
            break;
        } else {
            result[i] = 'a';
            i--;
        }
    }
    
    // Nếu không thể tạo chuỗi lớn hơn s hoặc kết quả >= t
    if(i < 0 || result >= t) {
        cout << "No such string" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
