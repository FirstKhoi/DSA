#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/785/problem/A
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    map<string, int> faces = {
        {"Tetrahedron", 4}, 
        {"Cube", 6}, 
        {"Octahedron", 8}, 
        {"Dodecahedron", 12}, 
        {"Icosahedron", 20}
    };
    
    int total = 0;
    while(n--) {
        string s; cin >> s;
        total += faces[s];
    }
    cout << total << endl;
    return 0;
}