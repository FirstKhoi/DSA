#include<bits/stdc++.h>
#include<vector>
using namespace std;
using ll = long long;
//https://codeforces.com/contest/263/problem/A
int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<vector<int>> a(5, vector<int>(5));
    for(int x = 0; x < 5; x++){
        for(int y = 0; y < 5; y++){
            cin >> a[x][y];
        }
    }
    int x = -1, y = -1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(a[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    cout << abs(x - 2) + abs(y - 2) << endl;
    return 0;
}