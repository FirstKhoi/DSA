#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/1054?view=statement
int main(){
  int k; cin >> k;
  vector<int> a(12);
  for(int i = 0; i < 12; ++i){
    cin >> a[i];
  }
	sort(a.rbegin(), a.rend());
  int sum = 0, months = 0;
  for(int i = 0; i < 12; ++i){
    if(sum >= k) break;
    sum += a[i];
    months++;
  }
  if(sum < k) cout << -1 << endl;
  else cout << months << endl;
}