#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://bigocoder.com/courses/252/lectures/3808/problems/494?view=statementgit
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    	int nA; cin >> nA;
  int nB; cin >> nB;
  vector<int> a(nA), b(nB);
  int k, m; cin >> k >> m;
  for(int i = 0; i < nA; ++i){
   	cin >> a[i];
  }
  for(int i = 0; i < nB; ++i){
    cin >> b[i];
  }
if (a[k - 1] < b[nB - m]) {
    cout << "YES";
} else {
    cout << "NO";
}
  return 0;
}