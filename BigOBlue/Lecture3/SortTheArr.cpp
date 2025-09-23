#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/534?view=statement
int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  int l = 0, r = n - 1;
  while(l + 1 < n && a[l] < a[l + 1]){
    ++l;
  }
  if(l == n - 1){
    cout << "yes\n1 1\n";
    return 0;
  }
  while (r > 0 && a[r - 1] <= a[r]) r--;
    // Đảo ngược đoạn [l, r]
    reverse(a.begin() + l, a.begin() + r + 1);
    // Kiểm tra lại mảng đã tăng dần chưa
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
    else cout << "no\n";
    return 0;
}