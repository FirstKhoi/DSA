#include <map>
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
//https://bigocoder.com/courses/252/lectures/3814/problems/530?view=statement

int main () {
     int n;
  cin >> n;
  vector<int> cc(n);
  int a;
  for(int i = 0; i < n;i++) {
    cin >> a;
    cc[i] =  a;
  }
 vector<int> ccs(n);
  ccs = cc;
  sort(ccs.begin(), ccs.end(),greater<int>());
  int g = 1;
  map<int,int> mymap;
  for(auto d : ccs) {
    if(mymap.find(d) == mymap.end()) {
    mymap[d] = g;
    g++;
  }
    else {
      g++;
    }
  }
  for(auto e : cc) {
    cout << mymap[e] << " ";
  }
}