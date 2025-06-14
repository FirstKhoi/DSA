#include<iostream>
#include<vector>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3824/problems/547?view=statement
/*
B1: Read n, n - 1 cạnh nối (u,v). Khởi tạo đồ thị có N đỉnh, n - 1 cạnh.
B2: chạy dfs từ đỉnh 1
B3: Khởi tạo min_dist là khoảng cách ngắn nhất và min_id là id của vùng có chỉ số nhỏ nhất.
B4: Đọc q và duyệt qua q vùng đất
    + Xét vùng đất Qi
    + Nếu (dist[Qi] < min_dist) hoặc (dist[Qi] == min_dist && Qi < min_id) thì cập nhật lại min_dist và min_id.
*/


int main(){
    return 0;
}